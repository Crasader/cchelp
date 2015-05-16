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
    
    Action* MoveByActionFactory::createAction(const Parameter &p, const ActionFactoryContext &ctx) const
    {
        float dur;
        if (!Json::type::deserialize(p["duration"], dur))
            return nullptr;
        
        cocos2d::Vec2 by;
        if (!Json::type::deserialize(p, by) || !Json::type::deserialize(p["by"], by))
            return nullptr;
        
        return cocos2d::MoveBy::create(dur, by);
    }
}