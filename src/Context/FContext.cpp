//
//  FContext.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/26/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "FContext.h"
#include "jsonserialization.h"

namespace ccHelp
{
    FContext::FContext(const Context &_ctx, const Json::Value &_js)
    : ctx(_ctx), js(_js)
    {
        
    }
    
    FContext::FContext(const FContext &fctx)
    : ctx(fctx.ctx), js(fctx.js)
    {
        
    }
    
    bool FContext::isContains(const std::string &k) const
    {
        return js.isMember(k);
    }
    
    bool FContext::isReference(const std::string &k) const
    {
        return js[k].isString() && js[k].asString().length() > 0 && js[k].asString()[0] == '@';
    }
    
    const Context& FContext::context() const
    {
        return ctx;
    }
    
#define FCONTEXT_GET(TYPE, CONTEXT_AS) \
    template <> \
    bool FContext::get<TYPE>(const std::string &k, TYPE &v) const \
    { \
        if (js.isMember(k)) \
        { \
            if (isReference(k)) \
            { \
                std::string ref = js[k].asString(); \
                ref = ref.substr(1, ref.length() - 1); \
                \
                return ctx[ref].CONTEXT_AS(v); \
            } \
            \
            return Json::type::deserialize(js[k], v); \
        } \
        \
        return false; \
    }
    
    FCONTEXT_GET(char, asByte);
    FCONTEXT_GET(unsigned char, asUByte);
    FCONTEXT_GET(short, asShort);
    FCONTEXT_GET(unsigned short, asUShort);
    FCONTEXT_GET(int, asInt);
    FCONTEXT_GET(unsigned int, asUInt);
    FCONTEXT_GET(long, asLong);
    FCONTEXT_GET(unsigned long, asULong);
    FCONTEXT_GET(float, asFloat);
    FCONTEXT_GET(double, asDouble);
    FCONTEXT_GET(bool, asBool);
    FCONTEXT_GET(std::string, asString);
#undef FCONTEXT_GET
}