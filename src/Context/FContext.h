//
//  FContext.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/26/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Context.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp
{
    class FContext
    {
    private:
        const Json::Value &js;
        const Context &ctx;
        
    public:
        FContext() = delete;
        FContext(const Context &ctx, const Json::Value &js);
        FContext(const FContext &ctx);
        FContext& operator=(const FContext&) = delete;
        
        template <typename T>
        bool get(const std::string &k, T &v) const
        {
            if (js.isMember(k))
            {
                if (isReference(k))
                {
                    std::string ref = js[k].asString();
                    ref = ref.substr(1, ref.length() - 1);
                    
                    return ctx[ref].asCustom<T>(v);
                }
                
                return Json::type::deserialize<T>(js[k], v);
            }
            
            return false;
        }
        
        bool isContains(const std::string &k) const;
        bool isReference(const std::string &k) const;
        
        const Context& context() const;
    };
}

#include "FContext.hpp"