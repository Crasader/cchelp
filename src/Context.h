//
//  Context.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/8/15.
//  Copyright (c) 2015 Less. All rights reserved.
//
#pragma once
#include <string>
#include "hash_container/hmap.h"

namespace ccHelp {
    class CustomBaseHolder
    {
    public:
        virtual ~CustomBaseHolder();
        virtual CustomBaseHolder* clone() const = 0;
    };
    
    template <typename T>
    class CustomHolder : public CustomBaseHolder
    {
    private:
        T data;
        
    public:
        CustomHolder(const T &t)
        : data(t) {}
        ~CustomHolder() {}
        
        const T& get() const
        {
            return data;
        }
        
        T& get()
        {
            return data;
        }
        
        CustomHolder<T>* clone() const override
        {
            return new CustomHolder<T>(data);
        }
    };
    
    struct ContextValue
    {
    public:
        enum Type : char
        {
            NONE,
            BYTE,
            UBYTE,
            _BOOL,
            SHORT,
            USHORT,
            INT,
            UINT,
            LONG,
            ULONG,
            FLOAT,
            DOUBLE,
            STRING,
            VOID_POINTER,
            CUSTOM_HOLDER
        };
        
    private:
        union {
            char vByte;
            unsigned char vUByte;
            bool vBool;
            short vShort;
            unsigned short vUShort;
            int vInt;
            unsigned int vUInt;
            long vLong;
            unsigned long vULong;
            float vFloat;
            double vDouble;
            std::string vString;
            void *vVoidPointer;
            CustomBaseHolder *vCustomHolder;
        };
        
        ContextValue::Type type;
        
    public:
        ContextValue();
        ContextValue(const ContextValue &ctxVal);
        ContextValue& operator=(const ContextValue &ctxVal);
        ContextValue(const ContextValue &&ctxVal);
        ContextValue& operator=(const ContextValue &&ctxVal);
        ~ContextValue();
        
        ContextValue(char v);
        ContextValue(unsigned char v);
        ContextValue(short v);
        ContextValue(unsigned short v);
        ContextValue(int v);
        ContextValue(unsigned int v);
        ContextValue(long v);
        ContextValue(unsigned long v);
        ContextValue(float v);
        ContextValue(double v);
        ContextValue(bool v);
        ContextValue(const std::string &v);
        ContextValue(void *v);
        
        template<typename T>
        static ContextValue makeCustom(const T& v);
        
    public:
        char asByte() const;
        unsigned char asUByte() const;
        short asShort() const;
        unsigned short asUShort() const;
        int asInt() const;
        unsigned int asUInt() const;
        long asLong() const;
        unsigned long asULong() const;
        float asFloat() const;
        double asDouble() const;
        bool asBool() const;
        const std::string& asString() const;
        
        template<typename T = void>
        T* asPointer() const;
        
        template<typename T>
        bool asCustom(T &t) const;
        
        ContextValue::Type getType() const;
        bool isNumeric() const;
        bool isRealNumber() const;
        bool isPointer() const;
        bool isString() const;
        bool isCustom() const;
        
        friend class Context;
    };
    
    class Context
    {
    private:
        hmap<std::string, ContextValue> valueMap;
        
    public:
        virtual ~Context();
        
        Context& putByte(const std::string &k, char v);
        Context& putUByte(const std::string &k, unsigned char v);
        Context& putShort(const std::string &k, short v);
        Context& putUShort(const std::string &k, unsigned short v);
        Context& putInt(const std::string &k, int v);
        Context& putUInt(const std::string &k, unsigned int v);
        Context& putLong(const std::string &k, long v);
        Context& putULong(const std::string &k, unsigned long v);
        Context& putFloat(const std::string &k, float v);
        Context& putDouble(const std::string &k, double v);
        Context& putBool(const std::string &k, bool v);
        Context& putString(const std::string &k, const std::string &v);
        
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
        const std::string& getString(const std::string &k) const;
        
        const ContextValue& getValue(const std::string &k) const;
        const ContextValue& operator[](const std::string &k) const;
        
        template <typename T>
        T* getPointer(const std::string &k) const;
        
        template <typename T>
        bool getCustom(const std::string &k, T& t) const;
        
        void remove(const std::string &k);
        unsigned int size() const;
        void clear();
    };
}

#include "Context.hpp"
