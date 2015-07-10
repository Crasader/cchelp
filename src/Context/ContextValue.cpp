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
        new (&vString) std::string(v);
    }
    
    ContextValue::ContextValue(void *v)
    {
        type = VOID_POINTER;
        vVoidPointer = v;
    }
    
    
    
    bool ContextValue::asByte(char &v) const
    {
        switch (type) {
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = static_cast<char>(vUByte);
                return true;
            case SHORT:
                v = static_cast<char>(vShort);
                return true;
            case USHORT:
                v = static_cast<char>(vUShort);
                return true;
            case INT:
                v = static_cast<char>(vInt);
                return true;
            case UINT:
                v = static_cast<char>(vUInt);
                return true;
            case LONG:
                v = static_cast<char>(vLong);
                return true;
            case ULONG:
                v = static_cast<char>(vULong);
                return true;
            case FLOAT:
                v = static_cast<char>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<char>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<char>((vBool)?1:0);
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
    
    bool ContextValue::asUByte(unsigned char &v) const
    {
        switch (type) {
            case UBYTE:
                v = vUByte;
                return true;
            case BYTE:
                v = static_cast<unsigned char>(vByte);
                return true;
            case SHORT:
                v = static_cast<unsigned char>(vShort);
                return true;
            case USHORT:
                v = static_cast<unsigned char>(vUShort);
                return true;
            case INT:
                v = static_cast<unsigned char>(vInt);
                return true;
            case UINT:
                v = static_cast<unsigned char>(vUInt);
                return true;
            case LONG:
                v = static_cast<unsigned char>(vLong);
                return true;
            case ULONG:
                v = static_cast<unsigned char>(vULong);
                return true;
            case FLOAT:
                v = static_cast<unsigned char>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<unsigned char>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<unsigned char>((vBool)?1:0);
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
    
    bool ContextValue::asUShort(unsigned short &v) const
    {
        switch (type) {
            case USHORT:
                v = vUShort;
                return true;
            case SHORT:
                v = static_cast<unsigned short>(vShort);
                return true;
            case BYTE:
                v = vByte;
                return true;
            case UBYTE:
                v = vUByte;
                return true;
            case INT:
                v = static_cast<unsigned short>(vInt);
                return true;
            case UINT:
                v = static_cast<unsigned short>(vUInt);
                return true;
            case LONG:
                v = static_cast<unsigned short>(vLong);
                return true;
            case ULONG:
                v = static_cast<unsigned short>(vULong);
                return true;
            case FLOAT:
                v = static_cast<unsigned short>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<unsigned short>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<unsigned short>((vBool)?1:0);
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
    
    bool ContextValue::asULong(unsigned long &v) const
    {
        switch (type) {
            case LONG:
                v = static_cast<unsigned long>(vLong);
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
                v = static_cast<unsigned long>(vFloat);
                return true;
            case DOUBLE:
                v = static_cast<unsigned long>(vDouble);
                return true;
            case _BOOL:
                v = static_cast<unsigned long>((vBool)?1:0);
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
                for (char &c : s) {c = tolower(c);}
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
        if (type == STRING)
        {
            v = vString;
            return true;
        }
        
        return false;
    }
    
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
            vString.~basic_string<char>();
        }
        
        memset(this, 0, sizeof(ContextValue));
        type = NONE;
    }
    
    const ContextValue ContextValue::EMPTY;
}
