//
//  KVDB.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/3/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "KVDB.h"
#include "IOHelper.h"

using std::string;

namespace ccHelp {
#define SAFE_DELETE(p) {if (p) delete p; p = nullptr;}
#define MAX_CAP 0x4000
#define UPDATE_CAP 0x1000
    
    KVDB::KVDB(const char *_path)
    : path(_path)
    {
        mKeyIndexes.reserve(MAX_CAP);
        mData.reserve(MAX_CAP);
        mUpdatedKey.reserve(UPDATE_CAP);
        mRemovedKey.reserve(UPDATE_CAP);
    }
    
    KVDB::~KVDB()
    {
        this->resetAll();
    }
    
    bool KVDB::reloadFromFile()
    {
        static char BUFFER[std::numeric_limits<unsigned short>::max()];
        
        IOHelper keyFile, valueFile;
        if (!keyFile.open(path.c_str(), "rb"))
            return false;
        
        if (!valueFile.open(indexFilePath().c_str(), "rb"))
        {
            keyFile.close();
            return false;
        }
        
        this->resetAll();
        
        keyFile.seek(0, SEEK_SET);
        uint nKeys = keyFile.read<uint>();
        
        // build keys
        for (uint i = 0; i < nKeys; ++i)
        {
            uint keyIndex = keyFile.tell();
            
            unsigned short keySize = keyFile.read<unsigned short>();
            keyFile.read(BUFFER, keySize);
            
            string key(BUFFER);
            if (key.empty())
            {
                // may be deleted key
                continue;
            }
            
            uint valueIndex = keyFile.read<uint>();
            valueFile.seekAndPush(valueIndex);
            
            // read value
            Value val;
            val.len = valueFile.read<unsigned short>();
            char *valData = new char[val.len];
            valueFile.read(valData, val.len);
            val.data = valData;
            
            valueFile.backAndPop();
            
            mData[key] = val;
            mKeyIndexes[key] = keyIndex;
        }
        
        keyFile.close();
        valueFile.close();
        return true;
    }
    
    bool KVDB::get(const std::string &k, void *v, uint max, uint *len) const
    {
        if (len)
        {
            *len = 0;
        }
        
        auto it = mData.find(k);
        if (it == mData.end())
            return false;
        
        if (len)
        {
            *len = 0;
        }
        memcpy(v, it->second.data, MIN(max, it->second.len));
        return true;
    }
    
    bool KVDB::set(const std::string &k, const void *v, int len)
    {
        bool isKeyExisted = false;
        auto it = mData.find(k);
        
        if (it != mData.end())
        {
            if (memcmp(v, it->second.data, len) == 0)
                return true;
            
            SAFE_DELETE(it->second.data);
            it->second.len = 0;
            
            isKeyExisted = true;
        }
        
        char *data = new char[len];
        memcpy(data, v, len);
        Value val;
        val.data = data;
        val.len = len;
        mData[k] = val;
        
        mUpdatedKey.insert(k);
        mRemovedKey.erase(k);
        
        return isKeyExisted;
    }
    
    bool KVDB::del(const std::string &k)
    {
        bool isKeyExisted = false;
        auto it = mData.find(k);
        
        if (it != mData.end())
        {
            SAFE_DELETE(it->second.data);
            it->second.len = 0;
            mData.erase(k);
            
            isKeyExisted = true;
        }
        
        mRemovedKey.insert(k);
        mUpdatedKey.erase(k);
        
        return isKeyExisted;
    }
    
    void KVDB::flush()
    {
        IOHelper keyFile, valueFile;
        if (!keyFile.open(path.c_str(), "rb+") &&
            !keyFile.open(path.c_str(), "wb+"))
        {
            return;
        }
        
        if (!valueFile.open(indexFilePath().c_str(), "rb+") &&
            !valueFile.open(indexFilePath().c_str(), "wb+"))
        {
            keyFile.close();
            return;
        }
        
        keyFile.seek(0);
        keyFile.write((uint) mData.size());
        
        // first handle removed keys
        for (auto k : mRemovedKey)
        {
            auto it = mKeyIndexes.find(k);
            if (it == mKeyIndexes.end())
                continue;
            
            keyFile.seek(it->second + sizeof(unsigned short));
            keyFile.write('\0');
            mKeyIndexes.erase(k);
        }
        mRemovedKey.clear();
        
        // update values for changed keys
        for (auto k : mUpdatedKey)
        {
            auto &val = mData.at(k);
            
            auto it = mKeyIndexes.find(k);
            if (it != mKeyIndexes.end())
            {
                // get value index of old key
                keyFile.seek((uint) (it->second + sizeof(unsigned short) + k.length()));
                uint valIndex = keyFile.peek<uint>();
                
                // move to value
                valueFile.seek(valIndex);
                uint oldValSize = valueFile.peek<unsigned short>();
                if (oldValSize < val.len)
                {
                    // ignore that chunk, write and end
                    valueFile.seek(0, SEEK_END);
                    valIndex = valueFile.tell();
                }
                keyFile.write(valIndex);
            }
            else
            {
                keyFile.seek(0, SEEK_END);
                mKeyIndexes[k] = keyFile.tell();
                
                keyFile.write((unsigned short) k.length());
                keyFile.write(k.c_str(), (uint) k.length());
                
                valueFile.seek(0, SEEK_END);
                keyFile.write(valueFile.tell());
            }
            
            valueFile.write(val.len);
            valueFile.write(val.data, val.len);
        }
        mUpdatedKey.clear();
        
        keyFile.flush();
        valueFile.flush();
        keyFile.close();
        valueFile.close();
    }
    
    void KVDB::persistent()
    {
        IOHelper keyFile, valueFile;
        
        if (!keyFile.open(path.c_str(), "wb"))
            return;
        
        if (!valueFile.open(indexFilePath().c_str(), "wb"))
        {
            keyFile.close();
            return;
        }
        
        mKeyIndexes.clear();
        mUpdatedKey.clear();
        mRemovedKey.clear();
        
        for (auto it : mData)
        {
            uint valIndex = valueFile.tell();
            valueFile.write(it.second.len);
            valueFile.write(it.second.data, it.second.len);
            
            uint keyIndex = keyFile.tell();
            keyFile.write((unsigned short) it.first.length());
            keyFile.write(it.first.c_str(), (uint) it.first.length());
            keyFile.write(valIndex);
            
            mKeyIndexes[it.first] = keyIndex;
        }
        
        keyFile.flush();
        valueFile.flush();
        keyFile.close();
        valueFile.close();
    }
    
    void KVDB::close()
    {
        this->persistent();
        this->resetAll();
    }
    
    void KVDB::resetAll()
    {
        for (auto it : mData)
        {
            SAFE_DELETE(it.second.data);
        }
        
        mData.clear();
        mKeyIndexes.clear();
        mUpdatedKey.clear();
        mRemovedKey.clear();
    }
    
    string KVDB::indexFilePath() const
    {
        return path + ".index";
    }
}