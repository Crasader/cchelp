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
    
    cocos2d::MoveBy* MoveByActionFactory::createAction(const Parameter &p, const ActionFactoryContext &ctx) const
    {
        float dur;
        cocos2d::Vec2 by;
        
        if ((Json::type::deserialize(p["duration"], dur) ||
             Json::type::deserialize(p["dur"], dur)) &&
            Json::type::deserialize(p["dx"], by.x) &&
            Json::type::deserialize(p["dy"], by.y))
        {
            return cocos2d::MoveBy::create(dur, by);
        }
        
        return nullptr;
    }
}