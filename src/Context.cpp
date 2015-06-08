//
//  Context.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/8/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Context.h"

namespace ccHelp
{
    CustomBaseHolder::~CustomBaseHolder()
    {
        
    }
    
    ContextValue::ContextValue(const ContextValue &ctxVal)
    {
        if (ctxVal.type == CUSTOM_HOLDER)
        {
            this->vCustomHolder = ctxVal.vCustomHolder->clone();
        }
        else
        {
            (*this) = ctxVal;
        }
        
        this->type = ctxVal.type;
    }
    
    ContextValue& ContextValue::operator=(const ContextValue &ctxVal)
    {
        if (this->type == CUSTOM_HOLDER)
        {
            delete vCustomHolder;
        }
        
        if (ctxVal.type == CUSTOM_HOLDER)
        {
            this->vCustomHolder = ctxVal.vCustomHolder->clone();
        }
        else
        {
            (*this) = ctxVal;
        }
        
        this->type = ctxVal.type;
        return *this;
    }
    
    ContextValue::ContextValue(const ContextValue &&ctxVal)
    {
        (*this) = ctxVal;
    }
    
    ContextValue& ContextValue::operator=(const ContextValue &&ctxVal)
    {
        if (this->type == CUSTOM_HOLDER)
        {
            delete vCustomHolder;
        }
        
        (*this) = ctxVal;
        return *this;
    }
    
    ContextValue::~ContextValue()
    {
        if (type == CUSTOM_HOLDER)
        {
            delete vCustomHolder;
            vCustomHolder = nullptr;
        }
    }
    
    ContextValue::ContextValue()
    {
        type = NONE;
        vVoidPointer = nullptr;
    }
    
    ContextValue::ContextValue(char v)
    {
        type = BYTE;
        vByte = v;
    }
    
    ContextValue::ContextValue(unsigned char v)
    {
        type = UBYTE;
        vUByte = v;
    }
    
    ContextValue::ContextValue(short v)
    {
        type = SHORT;
        vShort = v;
    }
    
    ContextValue::ContextValue(unsigned short v)
    {
        type = USHORT;
        vUShort = v;
    }
    
    ContextValue::ContextValue(int v)
    {
        type = INT;
        vInt = v;
    }
    
    ContextValue::ContextValue(unsigned int v)
    {
        type = UINT;
        vUInt = v;
    }
    
    ContextValue::ContextValue(long v)
    {
        type = LONG;
        vLong = v;
    }
    
    ContextValue::ContextValue(unsigned long v)
    {
        type = ULONG;
        vULong = v;
    }
    
    ContextValue::ContextValue(float v)
    {
        type = FLOAT;
        vFloat = v;
    }
    
    ContextValue::ContextValue(double v)
    {
        type = DOUBLE;
        vDouble = v;
    }
    
    ContextValue::ContextValue(bool v)
    {
        type = _BOOL;
        vBool = v;
    }
    
    ContextValue::ContextValue(const std::string &v)
    {
        type = STRING;
        vString = v;
    }
    
    ContextValue::ContextValue(void *v)
    {
        type = VOID_POINTER;
        vVoidPointer = v;
    }
    
    
    
    char ContextValue::asByte() const
    {
        assert(type == BYTE);
        return vByte;
    }
    
    unsigned char ContextValue::asUByte() const
    {
        assert(type == UBYTE);
        return vUByte;
    }
    
    short ContextValue::asShort() const
    {
        assert(type == SHORT);
        return vShort;
    }
    
    unsigned short ContextValue::asUShort() const
    {
        assert(type == USHORT);
        return vUShort;
    }
    
    int ContextValue::asInt() const
    {
        assert(type == INT);
        return vInt;
    }
    
    unsigned int ContextValue::asUInt() const
    {
        assert(type == UINT);
        return vUInt;
    }
    
    long ContextValue::asLong() const
    {
        assert(type == LONG);
        return vLong;
    }
    
    unsigned long ContextValue::asULong() const
    {
        assert(type == ULONG);
        return vULong;
    }
    
    float ContextValue::asFloat() const
    {
        assert(type == FLOAT);
        return vFloat;
    }
    
    double ContextValue::asDouble() const
    {
        assert(type == DOUBLE);
        return vDouble;
    }
    
    bool ContextValue::asBool() const
    {
        assert(type == _BOOL);
        return vBool;
    }
    
    const std::string& ContextValue::asString() const
    {
        assert(type == STRING);
        return vString;
    }
    
    ContextValue::Type ContextValue::getType() const
    {
        return type;
    }
    
    Context::~Context()
    {
        this->clear();
    }
    
    
    Context& Context::putByte(const std::string &k, char v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putUByte(const std::string &k, unsigned char v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putShort(const std::string &k, short v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putUShort(const std::string &k, unsigned short v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putInt(const std::string &k, int v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putUInt(const std::string &k, unsigned int v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putLong(const std::string &k, long v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putULong(const std::string &k, unsigned long v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putFloat(const std::string &k, float v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putDouble(const std::string &k, double v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putBool(const std::string &k, bool v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::putString(const std::string &k, const std::string &v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    
    char Context::getByte(const std::string &k) const
    {
        return valueMap.at(k).asByte();
    }
    
    unsigned char Context::getUByte(const std::string &k) const
    {
        return valueMap.at(k).asUShort();
    }
    
    short Context::getShort(const std::string &k) const
    {
        return valueMap.at(k).asShort();
    }
    
    unsigned short Context::getUShort(const std::string &k) const
    {
        return valueMap.at(k).asUShort();
    }
    
    int Context::getInt(const std::string &k) const
    {
        return valueMap.at(k).asInt();
    }
    
    unsigned int Context::getUInt(const std::string &k) const
    {
        return valueMap.at(k).asUInt();
    }
    
    long Context::getLong(const std::string &k) const
    {
        return valueMap.at(k).asLong();
    }
    
    unsigned long Context::getULong(const std::string &k) const
    {
        return valueMap.at(k).asULong();
    }
    
    float Context::getFloat(const std::string &k) const
    {
        return valueMap.at(k).asFloat();
    }
    
    double Context::getDouble(const std::string &k) const
    {
        return valueMap.at(k).asDouble();
    }
    
    bool Context::getBool(const std::string &k) const
    {
        return valueMap.at(k).asBool();
    }
    
    const std::string& Context::getString(const std::string &k) const
    {
        return valueMap.at(k).asString();
    }
    
    const ContextValue& Context::getValue(const std::string &k) const
    {
        return valueMap.at(k);
    }
    
    const ContextValue& Context::operator[](const std::string &k) const
    {
        return valueMap.at(k);
    }
    
    void Context::remove(const std::string &k)
    {
        auto it = valueMap.find(k);
        if (it == valueMap.end())
            return;
        
        valueMap.erase(it);
    }
    
    unsigned int Context::size() const
    {
        return (unsigned int) valueMap.size();
    }
    
    void Context::clear()
    {
        for (auto ite : valueMap)
        {
            if (ite.second.type == ite.second.CUSTOM_HOLDER)
            {
                delete ite.second.vCustomHolder;
            }
        }
        valueMap.clear();
    }
}