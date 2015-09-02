//
//  ContextValue.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/25/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include "msgpack/msgpack.hpp"

using msgpack::object;

namespace ccHelp {
    class Context;
    
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
        enum Type : byte
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
            byte vByte;
            ubyte vUByte;
            bool vBool;
            short vShort;
            ushort vUShort;
            int vInt;
            unsigned int vUInt;
            long vLong;
            ulong vULong;
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
        ~ContextValue();
        
        ContextValue(byte v);
        ContextValue(ubyte v);
        ContextValue(short v);
        ContextValue(ushort v);
        ContextValue(int v);
        ContextValue(unsigned int v);
        ContextValue(long v);
        ContextValue(ulong v);
        ContextValue(float v);
        ContextValue(double v);
        ContextValue(bool v);
        ContextValue(const std::string &v);
        ContextValue(void *v);
        
        template<typename T>
        static ContextValue makeCustom(const T& v);
        
    public:
        bool asByte(byte &v) const;
        bool asUByte(ubyte &v) const;
        bool asShort(short &v) const;
        bool asUShort(ushort &v) const;
        bool asInt(int &v) const;
        bool asUInt(unsigned int &v) const;
        bool asLong(long &v) const;
        bool asULong(ulong &v) const;
        bool asFloat(float &v) const;
        bool asDouble(double &v) const;
        bool asBool(bool &v) const;
        bool asString(std::string &v) const;
        
        template<typename T = void>
        bool asPointer(T *&p) const;
        
        template<typename T>
        bool asCustom(T &t) const;
        
        template <typename T>
        T as() const;
        
        ContextValue::Type getType() const;
        bool isNumeric() const;
        bool isIntegerNumber() const;
        bool isPointer() const;
        bool isString() const;
        bool isCustom() const;
        
        bool operator==(const ContextValue &v) const;
        bool operator!=(const ContextValue &v) const;
        
    private:
        void release();
        
    public:
        // supports msgpack
        template <typename Packer>
        void msgpack_pack(Packer& pk) const;
        void msgpack_unpack(msgpack::object o);
        template <typename MSGPACK_OBJECT>
        void msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const;
        
    public:
        static const ContextValue EMPTY;
        
        friend class Context;
    };
}

MSGPACK_ADD_ENUM(ccHelp::ContextValue::Type);

#include "ContextValue.hpp"