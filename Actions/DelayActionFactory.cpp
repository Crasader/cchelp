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
    
    cocos2d::DelayTime* DelayActionFactory::createAction(const AFContext &ctx) const
    {
        float dur;
        if (!ctx.getField("duration", dur) &&
            !ctx.getField("dur", dur))
        {
            return nullptr;
        }
        
        return cocos2d::DelayTime::create(dur);
    }
}