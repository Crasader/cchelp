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
    
    cocos2d::FadeTo* FadeToActionFactory::createAction(const AFContext &ctx) const
    {
        float dur;
        if (!ctx.getField("duration", dur) &&
            !ctx.getField("dur", dur))
        {
            return nullptr;
        }
        
        int opactity;
        if (!ctx.getField("opacity", opactity) &&
            !ctx.getField("opact", opactity))
        {
            return nullptr;
        }
        
        return cocos2d::FadeTo::create(dur, (GLubyte) opactity);
    }
}