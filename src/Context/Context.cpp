//
//  Context.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/26/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Context.h"

namespace ccHelp
{
    Context::Context(size_t cap)
    {
        this->setCapacity(cap);
    }
    
    Context::~Context()
    {
        
    }
    
    Context& Context::put(const std::string &k, char v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, unsigned char v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, short v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, unsigned short v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, int v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, unsigned int v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, long v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, unsigned long v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, float v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, double v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, bool v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    Context& Context::put(const std::string &k, const std::string &v)
    {
        valueMap[k] = ContextValue(v);
        return *this;
    }
    
    char Context::getByte(const std::string &k) const
    {
        char v;
        assert(getValue(k).asByte(v));
        return v;
    }
    
    unsigned char Context::getUByte(const std::string &k) const
    {
        unsigned char v;
        assert(getValue(k).asUByte(v));
        return v;
    }
    
    short Context::getShort(const std::string &k) const
    {
        short v;
        assert(getValue(k).asShort(v));
        return v;
    }
    
    unsigned short Context::getUShort(const std::string &k) const
    {
        unsigned short v;
        assert(getValue(k).asUShort(v));
        return v;
    }
    
    int Context::getInt(const std::string &k) const
    {
        int v;
        assert(getValue(k).asInt(v));
        return v;
    }
    
    unsigned int Context::getUInt(const std::string &k) const
    {
        unsigned int v;
        assert(getValue(k).asUInt(v));
        return v;
    }
    
    long Context::getLong(const std::string &k) const
    {
        long v;
        assert(getValue(k).asLong(v));
        return v;
    }
    
    unsigned long Context::getULong(const std::string &k) const
    {
        unsigned long v;
        assert(getValue(k).asULong(v));
        return v;
    }
    
    float Context::getFloat(const std::string &k) const
    {
        float v;
        assert(getValue(k).asFloat(v));
        return v;
    }
    
    double Context::getDouble(const std::string &k) const
    {
        double v;
        assert(getValue(k).asDouble(v));
        return v;
    }
    
    bool Context::getBool(const std::string &k) const
    {
        bool v;
        assert(getValue(k).asBool(v));
        return v;
    }
    
    std::string Context::getString(const std::string &k) const
    {
        std::string v;
        assert(getValue(k).asString(v));
        return v;
    }
    
    const ContextValue& Context::getValue(const std::string &k) const
    {
        return (valueMap.find(k) != valueMap.end())?(valueMap.at(k)):ContextValue::EMPTY;
    }
    
    const ContextValue& Context::operator[](const std::string &k) const
    {
        return getValue(k);
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
        valueMap.clear();
    }
    
    void Context::setCapacity(size_t cap)
    {
        valueMap.reserve(cap);
    }
    
    const Context Context::EMPTY{};
}