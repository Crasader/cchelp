//
//  ContextValue.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/25/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "ContextValue.h"

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
        else if (ctxVal.type == STRING)
        {
            new (&vString) std::string(ctxVal.vString);
        }
        else
        {
            memcpy(this, &ctxVal, sizeof(ContextValue));
        }
        
        this->type = ctxVal.type;
    }
    
    ContextValue& ContextValue::operator=(const ContextValue &ctxVal)
    {
        this->release();
        
        if (ctxVal.type == CUSTOM_HOLDER)
        {
            this->vCustomHolder = ctxVal.vCustomHolder->clone();
        }
        else if (ctxVal.type == STRING)
        {
            new (&vString) std::string(ctxVal.vString);
        }
        else
        {
            memcpy(this, &ctxVal, sizeof(ContextValue));
        }
        
        this->type = ctxVal.type;
        return *this;
    }
    
    ContextValue::ContextValue(const ContextValue &&ctxVal)
    {
        memcpy(this, &ctxVal, sizeof(ContextValue));
        this->type = ctxVal.type;
    }
    
    ContextValue::~ContextValue()
    {
        this->release();
    }
    
    ContextValue::ContextValue()
    {
        type = NONE;
        this->release();
    }
    
    ContextValue::ContextValue(byte v)
    {
        type = BYTE;
        vByte = v;
    }
    
    ContextValue::ContextValue(ubyte v)
    {
        type = UBYTE;
        vUByte = v;
    }
    
    ContextValue::ContextValue(short v)
    {
        type = SHORT;
        vShort = v;
    }
    
    ContextValue::ContextValue(ushort v)
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
    
    ContextValue::ContextValue(ulong v)
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
        new (&vString) std::string(v);
    }
    
    ContextValue::ContextValue(void *v)
    {
        type = VOID_POINTER;
        vVoidPointer = v;
    }
    
    
    
    bool ContextValue::asByte(byte &v) const
    {
        v = 0;
        switch (type) {
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = static_cast<byte>(vUByte);
                return true;
            case SHORT:
                v = static_cast<byte>(vShort);
                return true;
            case USHORT:
                v = static_cast<byte>(vUShort);
                return true;
            case INT:
                v = static_cast<byte>(vInt);
                return true;
            case UINT:
                v = static_cast<byte>(vUInt);
                return true;
            case LONG:
                v = static_cast<byte>(vLong);
                return true;
            case ULONG:
                v = static_cast<byte>(vULong);
                return true;
            case FLOAT:
                v = static_cast<byte>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<byte>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<byte>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asUByte(ubyte &v) const
    {
        v = 0;
        switch (type) {
            case UBYTE:
                v = vUByte;
                return true;
            case BYTE:
                v = static_cast<ubyte>(vByte);
                return true;
            case SHORT:
                v = static_cast<ubyte>(vShort);
                return true;
            case USHORT:
                v = static_cast<ubyte>(vUShort);
                return true;
            case INT:
                v = static_cast<ubyte>(vInt);
                return true;
            case UINT:
                v = static_cast<ubyte>(vUInt);
                return true;
            case LONG:
                v = static_cast<ubyte>(vLong);
                return true;
            case ULONG:
                v = static_cast<ubyte>(vULong);
                return true;
            case FLOAT:
                v = static_cast<ubyte>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<ubyte>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<ubyte>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asShort(short &v) const
    {
        v = 0;
        switch (type) {
            case SHORT:
                v = vShort;
                return true;
            case USHORT:
                v = static_cast<short>(vUShort);
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case INT:
                v = static_cast<short>(vInt);
                return true;
            case UINT:
                v = static_cast<short>(vUInt);
                return true;
            case LONG:
                v = static_cast<short>(vLong);
                return true;
            case ULONG:
                v = static_cast<short>(vULong);
                return true;
            case FLOAT:
                v = static_cast<short>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<short>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<short>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asUShort(ushort &v) const
    {
        v = 0;
        switch (type) {
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = static_cast<ushort>(vShort);
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case INT:
                v = static_cast<ushort>(vInt);
                return true;
            case UINT:
                v = static_cast<ushort>(vUInt);
                return true;
            case LONG:
                v = static_cast<ushort>(vLong);
                return true;
            case ULONG:
                v = static_cast<ushort>(vULong);
                return true;
            case FLOAT:
                v = static_cast<ushort>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<ushort>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<ushort>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asInt(int &v) const
    {
        v = 0;
        switch (type) {
            case INT:
                v = vInt;
                return true;
            case UINT:
                v = static_cast<int>(vUInt);
                return true;
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = vShort;
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case LONG:
                v = static_cast<int>(vLong);
                return true;
            case ULONG:
                v = static_cast<int>(vULong);
                return true;
            case FLOAT:
                v = static_cast<int>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<int>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<int>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asUInt(unsigned int &v) const
    {
        v = 0u;
        switch (type) {
            case UINT:
                v = vUInt;
                return true;
            case INT:
                v = static_cast<unsigned int>(vInt);
                return true;
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = vShort;
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case LONG:
                v = static_cast<unsigned int>(vLong);
                return true;
            case ULONG:
                v = static_cast<unsigned int>(vULong);
                return true;
            case FLOAT:
                v = static_cast<unsigned int>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<unsigned int>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<unsigned int>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asLong(long &v) const
    {
        v = 0l;
        switch (type) {
            case LONG:
                v = vLong;
                return true;
            case ULONG:
                v = static_cast<long>(vULong);
                return true;
            case INT:
                v = vInt;
                return true;
            case UINT:
                v = vUInt;
                return true;
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = vShort;
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case FLOAT:
                v = static_cast<long>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<long>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<long>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asULong(ulong &v) const
    {
        v = 0ul;
        switch (type) {
            case LONG:
                v = static_cast<ulong>(vLong);
                return true;
            case ULONG:
                v = vULong;
                return true;
            case INT:
                v = vInt;
                return true;
            case UINT:
                v = vUInt;
                return true;
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = vShort;
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case FLOAT:
                v = static_cast<ulong>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<ulong>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<ulong>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asFloat(float &v) const
    {
        v = 0.f;
        switch (type) {
            case FLOAT:
                v = vFloat;
                return true;
            case DOUBLE:
                v = static_cast<float>(vDouble);
                return true;
            case LONG:
                v = vLong;
                return true;
            case ULONG:
                v = static_cast<float>(vULong);
                return true;
            case INT:
                v = vInt;
                return true;
            case UINT:
                v = vUInt;
                return true;
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = vShort;
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case _BOOL:
                v = static_cast<float>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asDouble(double &v) const
    {
        v = 0.0;
        switch (type) {
            case DOUBLE:
                v = vDouble;
                return true;
            case FLOAT:
                v = vFloat;
                return true;
            case LONG:
                v = vLong;
                return true;
            case ULONG:
                v = static_cast<float>(vULong);
                return true;
            case INT:
                v = vInt;
                return true;
            case UINT:
                v = vUInt;
                return true;
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = vShort;
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case _BOOL:
                v = static_cast<double>((vBool)?1:0);
                return true;
            case STRING:
            {
                std::stringstream ss(vString);
                ss>>v;
                
                return !ss.fail();
            }
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asBool(bool &v) const
    {
        v = false;
        switch (type) {
            case _BOOL:
                v = vBool;
                return true;
            case BYTE:
                v = static_cast<bool>(vByte);
                return true;
            case UBYTE:
                v = static_cast<bool>(vUByte);
                return true;
            case SHORT:
                v = static_cast<bool>(vShort);
                return true;
            case USHORT:
                v = static_cast<bool>(vUShort);
                return true;
            case INT:
                v = static_cast<bool>(vInt);
                return true;
            case UINT:
                v = static_cast<bool>(vUInt);
                return true;
            case LONG:
                v = static_cast<bool>(vLong);
                return true;
            case ULONG:
                v = static_cast<bool>(vULong);
                return true;
            case FLOAT:
                v = static_cast<bool>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<bool>(vDouble);
                return true;
            case STRING:
            {
                std::string s = vString;
                for (byte &c : s) {c = tolower(c);}
                s.erase(0, s.find_first_not_of(" \t"));       //prefixing spaces
                s.erase(s.find_last_not_of(" \t") + 1);
                
                if ("true" == s || "yes" == s)
                {
                    v = true;
                    return true;
                }
                
                if ("false" == s || "no" == s || "" == s)
                {
                    v = false;
                    return true;
                }
                
                return false;
            }
                break;
                
            default:
                break;
        }
        
        return false;
    }
    
    bool ContextValue::asString(std::string &v) const
    {
        v.clear();
        if (type == STRING)
        {
            v = vString;
            return true;
        }
        
        return false;
    }
    
#define AS_METHOD(type, as_func, def_val) \
    template<> \
    type ContextValue::as<type>() const \
    { \
        type v = def_val; \
        if (as_func(v)) \
            return v; \
        \
        return def_val; \
    }
    
    AS_METHOD(byte, asByte, 0);
    AS_METHOD(ubyte, asUByte, 0);
    AS_METHOD(short, asShort, 0);
    AS_METHOD(ushort, asUShort, 0);
    AS_METHOD(int, asInt, 0);
    AS_METHOD(unsigned int, asUInt, 0u);
    AS_METHOD(long, asLong, 0l);
    AS_METHOD(ulong, asULong, 0ul);
    AS_METHOD(float, asFloat, 0.f);
    AS_METHOD(double, asDouble, 0.0);
    AS_METHOD(bool, asBool, false);
    AS_METHOD(std::string, asString, "");
    
#undef AS_METHOD
    
    ContextValue::Type ContextValue::getType() const
    {
        return type;
    }
    
    bool ContextValue::isNumeric() const
    {
        if ((type == BYTE) ||
            (type == UBYTE) ||
            (type == SHORT) ||
            (type == USHORT) ||
            (type == INT) ||
            (type == UINT) ||
            (type == LONG) ||
            (type == ULONG) ||
            (type == FLOAT) ||
            (type == DOUBLE) ||
            (type == _BOOL))
        {
            return true;
        }
        
        if (type == STRING)
        {
            double d = 0;
            std::stringstream ss(vString);
            
            ss>>d;
            return !ss.fail();
        }
        
        return false;
    }
    
    bool ContextValue::isIntegerNumber() const
    {
        if ((type == BYTE) ||
            (type == UBYTE) ||
            (type == SHORT) ||
            (type == USHORT) ||
            (type == INT) ||
            (type == UINT) ||
            (type == LONG) ||
            (type == ULONG) ||
            (type == _BOOL))
        {
            return true;
        }
        
        if (type == STRING)
        {
            long d = 0;
            std::stringstream ss(vString);
            
            ss>>d;
            return !ss.fail();
        }
        
        return false;
    }
    
    bool ContextValue::isPointer() const
    {
        return type == VOID_POINTER;
    }
    
    bool ContextValue::isString() const
    {
        return type == STRING;
    }
    
    bool ContextValue::isCustom() const
    {
        return type == CUSTOM_HOLDER;
    }
    
    bool ContextValue::operator==(const ccHelp::ContextValue &v) const
    {
        if (this->type != v.type)
            return false;
        
        switch (this->type)
        {
            case NONE:
                return true;
            case BYTE:
                return vByte == v.vByte;
            case UBYTE:
                return vUByte == v.vUByte;
            case SHORT:
                return vShort == v.vShort;
            case USHORT:
                return vUShort == v.vUShort;
            case INT:
                return vInt == v.vInt;
            case UINT:
                return vUInt == v.vUInt;
            case LONG:
                return vLong == v.vLong;
            case ULONG:
                return vULong == v.vULong;
            case FLOAT:
                return vFloat == v.vFloat;
            case DOUBLE:
                return vDouble == v.vDouble;
            case _BOOL:
                return vBool == v.vBool;
            case STRING:
                return vString == v.vString;
            case VOID_POINTER:
                return vVoidPointer == v.vVoidPointer;
            case CUSTOM_HOLDER:
                return vCustomHolder == v.vCustomHolder;
        }
    }
    
    bool ContextValue::operator!=(const ccHelp::ContextValue &v) const
    {
        return !this->operator==(v);
    }
    
    void ContextValue::release()
    {
        if (type == CUSTOM_HOLDER)
        {
            delete vCustomHolder;
        }
        else if (type == STRING)
        {
            vString.~basic_string<byte>();
        }
        
        memset(this, 0, sizeof(ContextValue));
        type = NONE;
    }
    
    const ContextValue ContextValue::EMPTY;
    
    void ContextValue::msgpack_unpack(msgpack::object o)
    {
        assert(o.type == msgpack::type::ARRAY);
        assert(o.via.array.size == 2);
        
        this->release();
        
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
                new (&vString) std::string();
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
}
