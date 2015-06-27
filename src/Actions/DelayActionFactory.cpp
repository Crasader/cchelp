//
//  DelayActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#include "DelayActionFactory.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp {
    
    cocos2d::DelayTime* DelayActionFactory::createAction(const FContext &ctx) const
    {
        float dur;
        if (!ctx.get("duration", dur) &&
            !ctx.get("dur", dur))
        {
            return nullptr;
        }
        
        return cocos2d::DelayTime::create(dur);
    }
}