//
//  PlaySoundActionFactory.cpp
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/18/15.
//
//

#include "PlaySoundActionFactory.h"
#include "jsonserialization.h"
#include "Sound.h"

namespace ccHelp {
    
    cocos2d::CallFunc* PlaySoundActionFactory::createAction(const Parameter &p, const ActionFactoryContext &ctx) const
    {
        string sound;
        if (!Json::type::deserialize(p["Sound"], sound) &&
            !Json::type::deserialize(p["1"], sound))
        {
            return nullptr;
        }
        
        return cocos2d::CallFunc::create([sound]() {
            ccHelp::Sound::getInstance()->playEffect(sound);
        });
    }
}