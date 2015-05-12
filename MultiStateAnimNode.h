//
//  StateAnimNode.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/1/15.
//
//

#ifndef GodRage_Endless_Revamp_StateAnimNode_h
#define GodRage_Endless_Revamp_StateAnimNode_h
#pragma once

#include "cocos2d.h"
#include "AnimationManager.h"
#include "jsoncpp/json2/json.h"
#include <string>

using std::string;

namespace ccHelp {
    enum AnimState
    {
        ANIMATED,
        PAUSED,
        STOPPED,
    };
    
    class MultiStateAnimNode : public cocos2d::Node
    {
    public:
        typedef hmap<string, cocos2d::Animation*> AnimationMap;
    private:
        
        cocos2d::Sprite *animSprite;
        cocos2d::Action *currentAction;
        AnimState animState;
        AnimationMap animMap;
        string state;
        
    public:
        MultiStateAnimNode();
        MultiStateAnimNode(const string& st);
        virtual ~MultiStateAnimNode();
        
        virtual bool initWithJson(const Json::Value &j);
        
        const string& getState() const;
        void setState(const string &st, bool updateAnim = true);
        
        cocos2d::Sprite* getInnerSprite() const;
        const AnimationMap& getAnimMap() const;
        
        void addAnimation(const string &st, cocos2d::Animation *anim);
        void addStaticAnimation(const string &st, cocos2d::SpriteFrame *spriteFrame);
        bool addAnimationByName(const string &st, const string &anim);
        
        void startAnimation();
        void stopAnimation();
        void restartAnimation();
        void pauseAnimation();
        void resumeAnimation();
        
        virtual void pause() override;
        virtual void resume() override;

        AnimState getAnimState() const;

    private:
        void releaseAll();
        
    public:
        static MultiStateAnimNode* create();
        static MultiStateAnimNode* createWithJsonFile(const string &fileName);
        static MultiStateAnimNode* createWithState(const string &st);
        static MultiStateAnimNode* createWithStateAndJsonFile(const string &st, const string &fileName);
    };
}

#endif
