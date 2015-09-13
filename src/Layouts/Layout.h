//
//  Layout.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#pragma once
#include "Def.h"
#include "jsoncpp/jsonserialization.h"
#include "cocos2d.h"

namespace ccHelp {
    
    class Layout : public virtual obj
    {
    public:
        class Parameter
        {
        private:
            static char BUFFER[0x1000];
            Json::Value json;
            
            bool getSubJson(Json::Value &v, uint index, const std::list<const char *> &keys) const;
            
        public:
            Parameter();
            Parameter(const Json::Value &js);
            
            template<typename T>
            bool get(T &v, uint index, ...) const
            {
                static char BUFFER[0x1000];
                
                va_list params;
                va_start(params, index);
                
                std::list<const char *> keys;
                const char *key = nullptr;
                while (true)
                {
                    key = va_arg(params, const char*);
                    
                    if (!key)
                        break;
                    
                    keys.push_back(key);
                }
                
                sprintf(BUFFER, "%u", index);
                keys.push_back(BUFFER);
                
                va_end(params);
                
                Json::Value js;
                if (!getSubJson(js, index, keys))
                    return false;
                
                Json::type::deserialize(js, v);
                
                return true;
            }
            
            template<typename T>
            bool get(T &v) const
            {
                return this->get<T>(v, 0, nullptr);
            }
            
            inline const Json::Value& getJson() const {return json;}
            
            static Parameter null;
        };
        
        virtual void doLayout(cocos2d::Node *node, const Layout::Parameter &par) const = 0;
    };
}

template<>
bool Json::type::deserialize<ccHelp::Layout::Parameter>(const Json::Value &js, ccHelp::Layout::Parameter &p);