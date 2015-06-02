//
//  ParallaxCamera.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/1/15.
//
//

#include "ParallaxCamera.h"

USING_NS_CC;

namespace ccHelp {
    class WarpperNode : public Node
    {
    public:
        virtual void removeChild(Node *child, bool cleanUp) override
        {
            ssize_t index = _children.getIndex(child);
            if (index != CC_INVALID_INDEX)
            {
                this->removeFromParentAndCleanup(cleanUp);
            }
        }
        
        static WarpperNode* create()
        {
            WarpperNode *warpper = new WarpperNode();
            if (!warpper->init())
            {
                delete warpper;
                return nullptr;
            }
            
            warpper->autorelease();
            return warpper;
        }
    };
    
    ParallaxCamera::ParallaxCamera() :
        eye(0, 0)
    {
        
    }
    
    void ParallaxCamera::addChild(cocos2d::Node *child, int z, int tag)
    {
        this->addChild(child, Vec2(1, 1), z, tag);
    }
    
    void ParallaxCamera::addChild(cocos2d::Node *child, int z, const string &name)
    {
        this->addChild(child, Vec2(1, 1), z, name);
    }
    
    void ParallaxCamera::addChild(cocos2d::Node *child, const Vec2 &ratio, int z, int tag)
    {
        Node *warpper = WarpperNode::create();
        warpper->addChild(child, z, tag);
        
        Node::addChild(warpper, z, tag);
        
        ParallaxObject prlObj;
        prlObj.warpper = warpper;
        prlObj.node = child;
        prlObj.ratio = ratio;
        prlObj.mult = Vec2(ratio.x - 1, ratio.y - 1);
        this->parallaxObjects.push_back(prlObj);
    }
    
    void ParallaxCamera::addChild(cocos2d::Node *child, const Vec2 &ratio, int z, const string &name)
    {
        Node *warpper = WarpperNode::create();
        warpper->addChild(child, z, name);
        
        Node::addChild(warpper, z, name);
        
        ParallaxObject prlObj;
        prlObj.warpper = warpper;
        prlObj.node = child;
        prlObj.ratio = ratio;
        prlObj.mult = Vec2(ratio.x - 1, ratio.y - 1);
        this->parallaxObjects.push_back(prlObj);
    }
    
    void ParallaxCamera::removeChild(cocos2d::Node *child, bool cleanup)
    {
        // explicit nil handling
        if (_children.empty())
        {
            return;
        }
        
        ssize_t index = _children.getIndex(child);
        if (index == CC_INVALID_INDEX)
        {
            auto ite = std::find_if(parallaxObjects.begin(), parallaxObjects.end(),
                                    [=](const ParallaxObject &prlObj) {return prlObj.node == child;});
            if (ite != parallaxObjects.end())
            {
                index = _children.getIndex(ite->warpper);
                parallaxObjects.erase(ite);
            }
        }
        else
        {
            auto ite = std::find_if(parallaxObjects.begin(), parallaxObjects.end(),
                                    [=](const ParallaxObject &prlObj) {return prlObj.warpper == child;});
            if (ite != parallaxObjects.end())
            {
                parallaxObjects.erase(ite);
            }
        }
        
        if( index != CC_INVALID_INDEX )
        {
            this->detachChild( child, index, cleanup );
        }
    }
    
    void ParallaxCamera::removeAllChildrenWithCleanup(bool cleanup)
    {
        this->parallaxObjects.clear();
        Node::removeAllChildrenWithCleanup(cleanup);
    }
    
    Size ParallaxCamera::getParallaxContentSize(const cocos2d::Node *child) const
    {
        for (auto &prlObj : parallaxObjects)
        {
            if (prlObj.node == child)
            {
                return Size(child->getContentSize().width / prlObj.ratio.x, child->getContentSize().height / prlObj.ratio.y);
            }
        }
        
        return Size::ZERO;
    }
    
    /*
     The positions are updated at visit because:
     - using a timer is not guaranteed that it will called after all the positions were updated
     - overriding "draw" will only precise if the children have a z > 0
     */
    void ParallaxCamera::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
    {
        for (auto &prlObj : parallaxObjects)
        {
            prlObj.warpper->setPositionX(prlObj.mult.x * prlObj.node->getPositionX() - prlObj.ratio.x * eye.x);
            prlObj.warpper->setPositionY(prlObj.mult.y * prlObj.node->getPositionY() - prlObj.ratio.y * eye.y);
        }
        
        Node::visit(renderer, parentTransform, parentFlags);
    }
}