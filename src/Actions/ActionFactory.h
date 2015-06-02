//
//  ActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "Def.h"
#include "ActionFactoryContext.h"
#include "hash_container/hmap.h"

using cocos2d::Action;
using std::string;

namespace ccHelp {
    class ActionFactory
    {
    public:
        typedef Json::Value Parameter;
        typedef vsson::VSSObject ShortcutParameter;
        
        virtual Action* createAction(const AFContext &ctx) const = 0;
        
        inline static ActionContext newContext()
        {
            return ActionContext();
        }
    };
}
