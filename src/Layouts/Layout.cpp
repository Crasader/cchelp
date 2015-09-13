//
//  Layout.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/7/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Layout.h"
#include "Def.h"
#include "vsson.h"
#include "Utils.h"

USING_NS_CC;

namespace ccHelp {
    char Layout::Parameter::BUFFER[0x1000];
    Layout::Parameter Layout::Parameter::null(Json::Value::null);
    
    Layout::Parameter::Parameter()
    : json(Json::Value::null)
    {
        
    }
    
    Layout::Parameter::Parameter(const Json::Value &js)
    {
        switch (js.type()) {
            case Json::ValueType::stringValue:
            {
                vsson::VSSObject vsson = vsson::VSSParser::parse(js.asString());
                json = Utils::jsonFromVsson(vsson);
            }
                break;
                
            case Json::ValueType::arrayValue:
            {
                for (uint i = 0; i < js.size(); ++i)
                {
                    this->json[StringUtils::format("%u", i)] = json[i];
                }
            }
                break;
                
            default:
                json = js;
                break;
        }
    }
    
    bool Layout::Parameter::getSubJson(Json::Value &v, uint index, const std::list<const char *> &keys) const
    {
        v = Json::Value::null;
        
        if (json.isObject())
        {
            for (auto *k : keys)
            {
                if (json.isMember(k))
                {
                    v = json[k];
                    return true;
                }
            }
            
            return false;
        }
        
        if (json.isArray())
        {
            if (json.size() > index)
            {
                v = json[index];
                return true;
            }
            
            return false;
        }
        
        if (index == 0)
        {
            v = json;
            return true;
        }
        
        return false;
    }
}

template<>
bool Json::type::deserialize<ccHelp::Layout::Parameter>(const Json::Value &js, ccHelp::Layout::Parameter &p)
{
    p = ccHelp::Layout::Parameter(js);
    return true;
}