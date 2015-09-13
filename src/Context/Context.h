//
//  Context.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/26/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "ContextValue.h"
#include "hash_container/hmap.h"

namespace ccHelp
{
    class Context
    {
    private:
        hmap<std::string, ContextValue> valueMap;
        
    public:
        Context() = default;
        Context(size_t cap);
        virtual ~Context();
        
        Context& put(const std::string &k, char v);
        Context& put(const std::string &k, unsigned char v);
        Context& put(const std::string &k, short v);
        Context& put(const std::string &k, unsigned short v);
        Context& put(const std::string &k, int v);
        Context& put(const std::string &k, unsigned int v);
        Context& put(const std::string &k, long v);
        Context& put(const std::string &k, unsigned long v);
        Context& put(const std::string &k, float v);
        Context& put(const std::string &k, double v);
        Context& put(const std::string &k, bool v);
        Context& put(const std::string &k, const std::string &v);
        Context& put(const std::string &k, const ContextValue &v);
        
        template <typename T>
        Context& putPointer(const std::string &k, T *v);
        
        template <typename T>
        Context& putCustom(const std::string &k, const T& v);
        
        char getByte(const std::string &k) const;
        unsigned char getUByte(const std::string &k) const;
        short getShort(const std::string &k) const;
        unsigned short getUShort(const std::string &k) const;
        int getInt(const std::string &k) const;
        unsigned int getUInt(const std::string &k) const;
        long getLong(const std::string &k) const;
        unsigned long getULong(const std::string &k) const;
        float getFloat(const std::string &k) const;
        double getDouble(const std::string &k) const;
        bool getBool(const std::string &k) const;
        std::string getString(const std::string &k) const;
        
        template <typename T>
        T* getPointer(const std::string &k) const;
        
        template <typename T>
        bool getCustom(const std::string &k, T& t) const;
        
        const ContextValue& getValue(const std::string &k) const;
        const ContextValue& operator[](const std::string &k) const;
        
        void remove(const std::string &k);
        unsigned int size() const;
        void clear();
        
        void setCapacity(size_t cap);
        const hmap<std::string, ContextValue>& asMap() const;
        
    public:
        // support msgpack
        MSGPACK_DEFINE(valueMap);
        
    public:
        static const Context EMPTY;
    };
}

#include "Context.hpp"
