//
//  ContextValue.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/25/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

namespace ccHelp {
    
    template <typename T>
    ContextValue ContextValue::makeCustom(const T &v)
    {
        ContextValue cv;
        cv.type = CUSTOM_HOLDER;
        cv.vCustomHolder = new CustomHolder<T>(v);
        
        return cv;
    }
    
    template <typename T>
    bool ContextValue::asPointer(T *&p) const
    {
        if (type == VOID_POINTER)
        {
            p = static_cast<T*>(vVoidPointer);
            return true;
        }
        
        return false;
    }
    
    template <typename T>
    bool ContextValue::asCustom(T &t) const
    {
        if (type == CUSTOM_HOLDER)
        {
            auto *p = dynamic_cast<CustomHolder<T>*>(vCustomHolder);
            if (!p)
                return false;
            
            t = p->get();
            return true;
        }
        
        return false;
    }
    
    
    template <typename Packer>
    void ContextValue::msgpack_pack(Packer& pk) const
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
    
    template <typename MSGPACK_OBJECT>
    void ContextValue::msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const
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
}
