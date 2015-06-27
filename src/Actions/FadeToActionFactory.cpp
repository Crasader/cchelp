//
//  FadeToActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#include "FadeToActionFactory.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp {
    
    cocos2d::FadeTo* FadeToActionFactory::createAction(const FContext &ctx) const
    {
        float dur;
        if (!ctx.get("duration", dur) &&
            !ctx.get("dur", dur))
        {
            return nullptr;
        }
        
        int opactity;
        if (!ctx.get("opacity", opactity) &&
            !ctx.get("opact", opactity))
        {
            return nullptr;
        }
        
        return cocos2d::FadeTo::create(dur, (GLubyte) opactity);
    }
}