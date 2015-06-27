//
//  ScaleToActionFactory.cpp
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/16/15.
//
//

#include "ScaleToActionFactory.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp {
    
    cocos2d::ScaleTo* ScaleToActionFactory::createAction(const FContext &ctx) const
    {
        float dur;
        if (!ctx.get("duration", dur) &&
            !ctx.get("dur", dur))
        {
            return nullptr;
        }
        
        cocos2d::Vec2 scaleXY(1, 1);
        
        if (ctx.get("x", scaleXY.x) ||
            ctx.get("y", scaleXY.y))
        {
            return cocos2d::ScaleTo::create(dur, scaleXY.x, scaleXY.y);
        }
        
        float &scale = scaleXY.x;
        if (ctx.get("scale", scale))
        {
            return cocos2d::ScaleTo::create(dur, scale);
        }
        
        return nullptr;
    }
}