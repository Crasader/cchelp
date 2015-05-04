//
//  AnimationManager.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//

#include "AnimationManager.h"
#include "jsoncpp/jsonserialization.h"

USING_NS_CC;
using namespace std;

namespace ccHelp {
    struct AnimationSpriteSheetData
    {
        struct AnimationData
        {
            std::string sprite;
            std::string name;
            float delay;
            
            std::vector<std::string> frames;
            
            JSONCPP_DEFINE("name", name, "delay", delay,
                           "frames", frames, "sprite_sheet", sprite);
        };
        
        
        std::string spriteSheetFile;
        std::vector<AnimationData> animations;
        
        JSONCPP_DEFINE("sprite_sheet", spriteSheetFile,
                       "animations", animations);
    };
    
    AnimationManager* AnimationManager::inst = new AnimationManager;
    
    uint AnimationManager::loadAnimationList(const std::string &listFile)
    {
        vector<string> animFiles;
        Json::Value json;
        Json::Reader reader;
        string content = FileUtils::getInstance()->getStringFromFile(listFile);
        
        reader.parse(content, json);
        Json::type::deserialize(json, animFiles);
        
        uint nAnim = 0;
        for (auto &animFile : animFiles)
        {
            nAnim += loadAnimation(animFile);
        }
        
        return nAnim;
    }
    
    uint AnimationManager::loadAnimation(const std::string &animFile)
    {
        Json::Reader reader;
        Json::Value root;
        
        string animData = FileUtils::getInstance()->getStringFromFile(animFile);
        reader.parse(animData, root);
        
        AnimationSpriteSheetData ssData;
        ssData.deserialize(root);
        
        if (!ssData.spriteSheetFile.empty())
        {
            string plist = StringUtils::format("%s.plist", ssData.spriteSheetFile.c_str());
            string texture = StringUtils::format("%s.png", ssData.spriteSheetFile.c_str());
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist, texture);
        }
        
        for (auto &animData : ssData.animations)
        {
            if (!animData.sprite.empty())
            {
                string plist = StringUtils::format("%s.plist", animData.sprite.c_str());
                string texture = StringUtils::format("%s.png", animData.sprite.c_str());
                SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist, texture);
            }
            else
            {
                animData.sprite = ssData.spriteSheetFile;
            }
            
            Vector<SpriteFrame *> frames(animData.frames.size());
            for (auto &frameName : animData.frames)
            {
                frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName));
            }
            
            Animation* anim = Animation::createWithSpriteFrames(frames);
            anim->setDelayPerUnit(animData.delay);
            
            AnimationCache::getInstance()->addAnimation(anim, animData.name);
            this->animSpriteName[animData.name] = animData.sprite;
        }
        
        return (uint) ssData.animations.size();
    }
    
    float AnimationManager::getAnimationDuration(const std::string &animName) const
    {
        return AnimationCache::getInstance()->getAnimation(animName)->getDuration();
    }
    
    const std::string& AnimationManager::getAnimationSpriteName(const std::string &animName) const
    {
        return this->animSpriteName.find(animName)->second;
    }
}