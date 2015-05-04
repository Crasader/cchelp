//
//  AnimationManager.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//
#pragma once

#include <stdio.h>
#include "Def.h"
#include "cocos2d.h"
#include "hmap.h"
#include <vector>
#include <string>

namespace ccHelp {
    class AnimationManager
    {
    private:
        static AnimationManager* inst;
        AnimationManager() {};  // block constructor for singleton
        
        hmap<std::string, std::string> animSpriteName;
        
    public:
        inline static AnimationManager* getInstance() {return inst;}
        
        uint loadAnimationList(const std::string &listFile);
        uint loadAnimation(const std::string &animFile);
        float getAnimationDuration(const std::string &animName) const;
        const std::string& getAnimationSpriteName(const std::string &animName) const;
    };
}
