//
//  ActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "Def.h"
#include "../Context/FContext.h"
#include "hash_container/hmap.h"

using cocos2d::Action;
using std::string;

namespace ccHelp {
    typedef std::function<void(void)> CallFuncFunction;
    typedef std::function<void(cocos2d::Node*)> CallFuncNFunction;
    
    class ActionFactory
    {
    public:
        virtual ~ActionFactory();
        typedef Json::Value Parameter;
        
        virtual Action* createAction(const FContext &ctx) const = 0;
    };
}
