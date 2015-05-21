//
//  Context2.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/20/15.
//
//

#pragma once
#include "Def.h"
#include "jsonserialization.h"
#include "vsson.h"
#include "lexical_cast.h"
#include <type_traits>

namespace ccHelp {
    class Context2
    {
    public:
        template <typename T>
        T get(const std::string &k) const;
        
        template <typename T>
        Context2& put(const std::string &k, const T& data);
    };

    class Context3
    {
    private:
        Context2 ctx2;
        Json::Value js;
        vsson::VSSObject vss;
        
    public:
        template<typename T>
        T get(string k) const
        {
            enum TYPE {JSON, VSSON, CONTEXT};
            
            TYPE type = js.isMember(k)?JSON:((vss.member(k)?VSSON:CONTEXT));
            
            if (type != CONTEXT)
            {
                string ctxField;
                if (type == JSON && js[k].isString())
                {
                    ctxField = js[k].asString();
                }
                else if (type == VSSON)
                {
                    ctxField = vss[k].asString();
                }
                
                if (!ctxField.empty() && ctxField[0] == '@')
                {
                    type = CONTEXT;
                    k = ctxField.substr(1, ctxField.length() - 1);
                }
            }
        }
    };
}