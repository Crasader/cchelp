//
//  ScaleToActionFactory.cpp
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/16/15.
//
//

#include "ScaleToActionFactory.h"
#include "jsonserialization.h"

namespace ccHelp {
    
    cocos2d::ScaleTo* ScaleToActionFactory::createAction(const AFContext &ctx) const
    {
        float dur;
        if (!ctx.getField("duration", dur) &&
            !ctx.getField("dur", dur))
        {
            return nullptr;
        }
        
        cocos2d::Vec2 scaleXY(1, 1);
        
        if (ctx.getField("x", scaleXY.x) ||
            ctx.getField("y", scaleXY.y))
        {
            return cocos2d::ScaleTo::create(dur, scaleXY.x, scaleXY.y);
        }
        
        float &scale = scaleXY.x;
        if (ctx.getField("scale", scale))
        {
            return cocos2d::ScaleTo::create(dur, scale);
        }
        
        return nullptr;
    }
}