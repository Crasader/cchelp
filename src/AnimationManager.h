//
//  AnimationManager.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//
#pragma once

#include "Def.h"
#include "cocos2d.h"
#include "hash_container/hmap.h"
#include "jsoncpp/jsonserialization.h"

namespace ccHelp {
    struct AnimationSpriteSheetData
    {
        struct AnimationData
        {
            std::string sprite;
            std::string name;
            float delay;
            bool nonCached;
            
            std::vector<std::string> frames;
            
            JSONCPP_DEFINE("name", name, "delay", delay,
                           "non_cached", nonCached,
                           "frames", frames, "sprite_sheet", sprite);
        };
        
        
        std::string spriteSheetFile;
        std::vector<AnimationData> animations;
        
        JSONCPP_DEFINE("sprite_sheet", spriteSheetFile,
                       "animations", animations);
    };
    
    class AnimationManager
    {
    private:
        static AnimationManager* inst;
        AnimationManager() {};  // block constructor for singleton
        
        hmap<std::string, std::string> animSpriteName;
        hmap<std::string, AnimationSpriteSheetData> NonCachedAnim;
        
    public:
        inline static AnimationManager* getInstance() {return inst;}
        
        uint loadAnimationList(const std::string &listFile);
        uint loadAnimation(const std::string &animFile);
        float getAnimationDuration(const std::string &animName) const;
        const std::string& getAnimationSpriteName(const std::string &animName) const;
    };
}

JSONCPP_REGISTER_CUSTOM_CLASS(ccHelp::AnimationSpriteSheetData::AnimationData);
JSONCPP_REGISTER_CUSTOM_CLASS(ccHelp::AnimationSpriteSheetData);
