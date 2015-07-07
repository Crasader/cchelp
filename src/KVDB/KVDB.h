//
//  KVDB.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/3/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include "hash_container/hmap.h"
#include "hash_container/hset.h"
#include "Hash.h"

namespace ccHelp
{
    class KVDB
    {
    private:
        struct Value
        {
            char *data;
            unsigned short len;
            unsigned short cap;
        };
        
        const std::string path;
        
        hmap<std::string, Value> mData;
        
        hmap<std::string, uint> mKeyIndexes;
        hset<std::string> mUpdatedKey, mRemovedKey;
        
        std::string indexFilePath() const;
        void resetAll();
        
    public:
        KVDB(const char *_path);
        ~KVDB();
        
        bool reloadFromFile();
        
        bool get(const std::string &k, void *v, uint max = 0xffffffff, uint *len = nullptr) const;
        bool set(const std::string &k, const void *v, uint len, uint cap = 0);
        bool del(const std::string &k);
        
        template <typename T>
        T get(const std::string &k, T defaultVal) const
        {
            T t;
            if (get(k, &t, sizeof(T)))
            {
                return t;
            }
            
            return defaultVal;
        }
        
        template <typename T>
        void set(const std::string &k, T val)
        {
            set(k, &val, sizeof(T));
        }
        
        void flush();
        void persistent();
        
        void close();
        
    private:
        KVDB(const KVDB &db);
        KVDB& operator=(const KVDB &db) = delete;
    };
}