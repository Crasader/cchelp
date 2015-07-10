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
        bool asByte(char &v) const;
        bool asUByte(unsigned char &v) const;
        bool asShort(short &v) const;
        bool asUShort(unsigned short &v) const;
        bool asInt(int &v) const;
        bool asUInt(unsigned int &v) const;
        bool asLong(long &v) const;
        bool asULong(unsigned long &v) const;
        bool asFloat(float &v) const;
        bool asDouble(double &v) const;
        bool asBool(bool &v) const;
        bool asString(std::string &v) const;
        
        template<typename T = void>
        bool asPointer(T *&p) const;
        
        template<typename T>
        bool asCustom(T &t) const;
        
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
        void msgpack_pack(Packer& pk) const
        {
            pk.pack_array(2);
            
            pk.pack(this->type);
            switch (this->type)
            {
                case NONE:
                    pk.pack('\0');
                    break;
                case BYTE:
                    pk.pack(vByte);
                    break;
                case UBYTE:
                    pk.pack(vUByte);
                    break;
                case _BOOL:
                    pk.pack(vBool);
                    break;
                case SHORT:
                    pk.pack(vShort);
                    break;
                case USHORT:
                    pk.pack(vUShort);
                    break;
                case INT:
                    pk.pack(vInt);
                    break;
                case UINT:
                    pk.pack(vUInt);
                    break;
                case LONG:
                    pk.pack(vLong);
                    break;
                case ULONG:
                    pk.pack(vULong);
                    break;
                case FLOAT:
                    pk.pack(vFloat);
                    break;
                case DOUBLE:
                    pk.pack(vDouble);
                    break;
                case STRING:
                    pk.pack(vString);
                    break;
                case VOID_POINTER:
                    assert(false);
                    break;
                case CUSTOM_HOLDER:
                    assert(false);
                    break;
            }
        }
        
        inline void msgpack_unpack(msgpack::object o)
        {
            assert(o.type == msgpack::type::ARRAY);
            assert(o.via.array.size == 2);
            
            o.via.array.ptr[0].convert(&type);
            switch (this->type)
            {
                case NONE:
                    break;
                case BYTE:
                    o.via.array.ptr[1].convert(&vByte);
                    break;
                case UBYTE:
                    o.via.array.ptr[1].convert(&vUByte);
                    break;
                case _BOOL:
                    o.via.array.ptr[1].convert(&vBool);
                    break;
                case SHORT:
                    o.via.array.ptr[1].convert(&vShort);
                    break;
                case USHORT:
                    o.via.array.ptr[1].convert(&vUShort);
                    break;
                case INT:
                    o.via.array.ptr[1].convert(&vInt);
                    break;
                case UINT:
                    o.via.array.ptr[1].convert(&vUInt);
                    break;
                case LONG:
                    o.via.array.ptr[1].convert(&vLong);
                    break;
                case ULONG:
                    o.via.array.ptr[1].convert(&vULong);
                    break;
                case FLOAT:
                    o.via.array.ptr[1].convert(&vFloat);
                    break;
                case DOUBLE:
                    o.via.array.ptr[1].convert(&vDouble);
                    break;
                case STRING:
                    o.via.array.ptr[1].convert(&vString);
                    break;
                case VOID_POINTER:
                    assert(false);
                    break;
                case CUSTOM_HOLDER:
                    assert(false);
                    break;
            }
        }
        
        template <typename MSGPACK_OBJECT>
        void msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const
        {
            o->type = msgpack::type::ARRAY;
            o->via.array.ptr = (object*)z->malloc(sizeof(object)*2);
            o->via.array.size = 2;
            
            o->via.array.ptr[0] = object(type, z);
            switch (this->type)
            {
                case NONE:
                    break;
                case BYTE:
                    o->via.array.ptr[1] = object(vByte, z);
                    break;
                case UBYTE:
                    o->via.array.ptr[1] = object(vUByte, z);
                    break;
                case _BOOL:
                    o->via.array.ptr[1] = object(vBool, z);
                    break;
                case SHORT:
                    o->via.array.ptr[1] = object(vShort, z);
                    break;
                case USHORT:
                    o->via.array.ptr[1] = object(vUShort, z);
                    break;
                case INT:
                    o->via.array.ptr[1] = object(vInt, z);
                    break;
                case UINT:
                    o->via.array.ptr[1] = object(vUInt, z);
                    break;
                case LONG:
                    o->via.array.ptr[1] = object(vLong, z);
                    break;
                case ULONG:
                    o->via.array.ptr[1] = object(vULong, z);
                    break;
                case FLOAT:
                    o->via.array.ptr[1] = object(vFloat, z);
                    break;
                case DOUBLE:
                    o->via.array.ptr[1] = object(vDouble, z);
                    break;
                case STRING:
                    o->via.array.ptr[1] = object(vString, z);
                    break;
                case VOID_POINTER:
                    assert(false);
                    break;
                case CUSTOM_HOLDER:
                    assert(false);
                    break;
            }
        }
        
    public:
        static const ContextValue EMPTY;
        
        friend class Context;
    };
}

MSGPACK_ADD_ENUM(ccHelp::ContextValue::Type);

#include "ContextValue.hpp"