//
//  AnimateActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#include "AnimateActionFactory.h"
#include "jsonserialization.h"

namespace ccHelp {
    
    cocos2d::Animate* AnimateActionFactory::createAction(const AFContext &ctx) const
    {
        string animName;
        if (!ctx.getField("animation", animName) &&
            !ctx.getField("anim", animName) &&
            !ctx.getField("1", animName))
        {
            return nullptr;
        }
        
        auto *anim = cocos2d::AnimationCache::getInstance()->getAnimation(animName);
        if (!anim)
            return nullptr;
        
        return cocos2d::Animate::create(anim);
    }
}