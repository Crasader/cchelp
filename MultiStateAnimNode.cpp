//
//  MultiStateAnimNode.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/1/15.
//
//

#include "MultiStateAnimNode.h"
#include "jsonserialization.h"

USING_NS_CC;

namespace ccHelp {
    
    MultiStateAnimNode::MultiStateAnimNode() :
    animSprite(nullptr), animState(AnimState::STOPPED), currentAction(nullptr)
    {
        
    }
    
    MultiStateAnimNode::MultiStateAnimNode(const string& st) :
    animSprite(nullptr), animState(AnimState::STOPPED), currentAction(nullptr), state(st)
    {
        
    }
    
    MultiStateAnimNode::~MultiStateAnimNode()
    {
        this->releaseAll();
    }
    
    bool MultiStateAnimNode::initWithJson(const Json::Value &j)
    {
        if (!Node::init())
            return false;
        
        hmap<string, string> data;
        Json::type::deserialize(j, data);
        
        for (auto ite : data)
        {
            if (!addAnimationByName(ite.first, ite.second))
            {
                this->releaseAll();
                return false;
            }
        }
        
        return true;
    }
    
    const string& MultiStateAnimNode::getState() const {return this->state;}
    void MultiStateAnimNode::setState(const string &st, bool updateAnim)
    {
        this->state = st;
        if (updateAnim)
        {
            this->restartAnimation();
        }
    }
    
    Sprite* MultiStateAnimNode::getInnerSprite() const {return this->animSprite;}
    const MultiStateAnimNode::AnimationMap& MultiStateAnimNode::getAnimMap() const {return this->animMap;}
    
    void MultiStateAnimNode::addAnimation(const string &st, Animation *anim)
    {
        anim->retain();
        animMap[st] = anim;
    }
    
    void MultiStateAnimNode::addStaticAnimation(const string &st, SpriteFrame *spriteFrame)
    {
        auto animation = Animation::create();
        animation->addSpriteFrame(spriteFrame);
        addAnimation(st, animation);
    }
    
    bool MultiStateAnimNode::addAnimationByName(const string &st, const string &anim)
    {
        auto animation = AnimationCache::getInstance()->getAnimation(anim);
        if (!animation)
        {
            auto sprFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(anim);
            if (!sprFrame)
            {
                return false;
            }
            
            animation = Animation::create();
            animation->addSpriteFrame(sprFrame);
        }
        
        animation->retain();
        animMap[st] = animation;
        
        return true;
    }
    
    void MultiStateAnimNode::startAnimation()
    {
        CCASSERT(this->animState == AnimState::STOPPED, "AnimState must be STOPPED");
        
        auto ite = animMap.find(state);
        if (ite == animMap.end())
            return;
        
        Animation* anim = ite->second;
        auto animTexture = anim->getFrames().front()->getSpriteFrame()->getTexture();
        if (!animSprite || animSprite->getTexture() != animTexture)
        {
            // remake animSprite
            auto oldSprite = animSprite;
            animSprite = Sprite::createWithTexture(animTexture, Rect::ZERO);
            
            // copy data
            if (oldSprite)
            {
                // too lazy
                oldSprite->removeFromParent();
            }
            
            this->addChild(animSprite);
        }
        
        currentAction = RepeatForever::create(Animate::create(anim));
        animSprite->runAction(currentAction);
        this->animState = AnimState::ANIMATED;
    }
    
    void MultiStateAnimNode::stopAnimation()
    {
        CCASSERT(this->animState != AnimState::STOPPED, "AnimState cannot be STOPPED");
        
        if (!animSprite)
        {
            this->state = AnimState::STOPPED;
            return;
        }
        
        animSprite->stopAction(currentAction);
        currentAction = nullptr;
        
        this->animState = AnimState::STOPPED;
    }
    
    void MultiStateAnimNode::restartAnimation()
    {
        if (this->animState != AnimState::STOPPED)
        {
            this->stopAnimation();
        }
        this->startAnimation();
    }
    
    void MultiStateAnimNode::pauseAnimation()
    {
        CCASSERT(this->animState == AnimState::ANIMATED, "AnimState must be be animated");
        
        if (!animSprite)
            return;
        
        animSprite->pause();
        this->animState = AnimState::PAUSED;
    }
    
    void MultiStateAnimNode::resumeAnimation()
    {
        CCASSERT(this->animState == AnimState::PAUSED, "AnimState must be be paused");
        
        if (!animSprite)
            return;
        
        animSprite->resume();
        this->animState = AnimState::ANIMATED;
    }
    
    AnimState MultiStateAnimNode::getAnimState() const {return this->animState;}
    
    void MultiStateAnimNode::releaseAll()
    {
        for (auto ite : this->animMap)
        {
            ite.second->release();
        }
        this->animMap.clear();
    }
    
    MultiStateAnimNode* MultiStateAnimNode::create()
    {
        MultiStateAnimNode* msaNode = new MultiStateAnimNode();
        if (!msaNode->init())
        {
            delete msaNode;
            return nullptr;
        }
        
        msaNode->autorelease();
        return msaNode;
    }
    
    MultiStateAnimNode* MultiStateAnimNode::createWithJsonFile(const string &fileName)
    {
        string content = FileUtils::getInstance()->getStringFromFile(fileName);
        Json::Value js;
        Json::Reader reader;
        
        bool parseSucc = reader.parse(content, js);
        
        if (!parseSucc)
            return nullptr;
        
        MultiStateAnimNode* msaNode = new MultiStateAnimNode();
        if (!msaNode->initWithJson(js))
        {
            delete msaNode;
            return nullptr;
        }
        
        msaNode->autorelease();
        return msaNode;
    }
    
    MultiStateAnimNode* MultiStateAnimNode::createWithState(const string &st)
    {
        MultiStateAnimNode* msaNode = new MultiStateAnimNode(st);
        if (!msaNode->init())
        {
            delete msaNode;
            return nullptr;
        }
        
        msaNode->autorelease();
        return msaNode;
    }
    
    MultiStateAnimNode* MultiStateAnimNode::createWithStateAndJsonFile(const string &st, const string &fileName)
    {
        string content = FileUtils::getInstance()->getStringFromFile(fileName);
        Json::Value js;
        Json::Reader reader;
        
        bool parseSucc = reader.parse(content, js);
        
        if (!parseSucc)
            return nullptr;
        
        MultiStateAnimNode* msaNode = new MultiStateAnimNode(st);
        if (!msaNode->initWithJson(js))
        {
            delete msaNode;
            return nullptr;
        }
        
        msaNode->autorelease();
        return msaNode;
    }
    
    void MultiStateAnimNode::pause()
    {
        Node::pause();
        
        if (this->animState == AnimState::ANIMATED)
        {
            this->pauseAnimation();
        }
    }
    
    void MultiStateAnimNode::resume()
    {
        Node::resume();
        
        if (this->animState == AnimState::PAUSED)
        {
            this->resumeAnimation();
        }
    }
}
