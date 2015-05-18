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
    
    cocos2d::ScaleTo* ScaleToActionFactory::createAction(const Parameter &p, const ActionFactoryContext &ctx) const
    {
        float dur;
        cocos2d::Vec2 scaleXY(1, 1);
        if (!Json::type::deserialize(p["duration"], dur) &&
            !Json::type::deserialize(p["dur"], dur))
            return nullptr;
        
        bool isScaleXY = false;
        isScaleXY |= Json::type::deserialize(p["x"], scaleXY.x);
        isScaleXY |= Json::type::deserialize(p["y"], scaleXY.y);
        
        if (isScaleXY)
        {
            return cocos2d::ScaleTo::create(dur, scaleXY.x, scaleXY.y);
        }
        
        float &scale = scaleXY.x;
        if (Json::type::deserialize(p["scale"], scale))
        {
            return cocos2d::ScaleTo::create(dur, scale);
        }
        
        return nullptr;
    }
}