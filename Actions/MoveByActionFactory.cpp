//
//  MoveByActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/16/15.
//
//

#include "MoveByActionFactory.h"
#include "jsonserialization.h"

namespace ccHelp {
    
    cocos2d::MoveBy* MoveByActionFactory::createAction(const AFContext &ctx) const
    {
        float dur;
        cocos2d::Vec2 by;
        
        if (!ctx.getField("duration", dur) &&
            !ctx.getField("dur", dur))
        {
            return nullptr;
        }
        
        if (!ctx.getField("by", by) &&
            !ctx.getField("dx", by.x) &&
            !ctx.getField("dy", by.y))
        {
            return nullptr;
        }
        
        return cocos2d::MoveBy::create(dur, by);
    }
}