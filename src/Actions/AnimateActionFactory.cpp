//
//  AnimateActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#include "AnimateActionFactory.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp {
    
    cocos2d::Animate* AnimateActionFactory::createAction(const FContext &ctx) const
    {
        string animName;
        if (!ctx.get("animation", animName) &&
            !ctx.get("anim", animName) &&
            !ctx.get("1", animName))
        {
            return nullptr;
        }
        
        auto *anim = cocos2d::AnimationCache::getInstance()->getAnimation(animName);
        if (!anim)
            return nullptr;
        
        return cocos2d::Animate::create(anim);
    }
}