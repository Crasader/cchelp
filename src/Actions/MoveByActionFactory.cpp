//
//  MoveByActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/16/15.
//
//

#include "MoveByActionFactory.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp {
    
    cocos2d::MoveBy* MoveByActionFactory::createAction(const FContext &ctx) const
    {
        float dur;
        cocos2d::Vec2 by;
        
        if (!ctx.get("duration", dur) &&
            !ctx.get("dur", dur))
        {
            return nullptr;
        }
        
        if (!ctx.get("by", by) &&
            !ctx.get("dx", by.x) &&
            !ctx.get("dy", by.y))
        {
            return nullptr;
        }
        
        return cocos2d::MoveBy::create(dur, by);
    }
}