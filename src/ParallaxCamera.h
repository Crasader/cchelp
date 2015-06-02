//
//  ParallaxCamera.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/1/15.
//
//

#ifndef __GodRage_Endless_Revamp__ParallaxCamera__
#define __GodRage_Endless_Revamp__ParallaxCamera__

#include <stdio.h>
#include "cocos2d.h"
#include "hash_container/hmap.h"
using std::string;

namespace ccHelp {
    class ParallaxCamera : public cocos2d::Node
    {
    private:
        struct ParallaxObject
        {
            cocos2d::Node *warpper, *node;
            cocos2d::Vec2 ratio, mult;
        };
        
        std::vector<ParallaxObject> parallaxObjects;
        cocos2d::Vec2 eye;
        
    public:
        ParallaxCamera();
        
        inline virtual void addChild(Node *child) {Node::addChild(child);}
        inline virtual void addChild(Node *child, int z) {Node::addChild(child, z);}
        virtual void addChild(Node *child, int z, int tag) override;
        virtual void addChild(Node *child, int z, const string &name) override;
        virtual void removeChild(Node *child, bool cleanup = true) override;
        virtual void removeAllChildrenWithCleanup(bool cleanup = true) override;
        
        inline virtual void addChild(Node *child, const cocos2d::Vec2 &ratio, int z) {addChild(child, ratio, z, child->getName());}
        inline virtual void addChild(Node *child, const cocos2d::Vec2 &ratio) {addChild(child, ratio, child->getLocalZOrder(), child->getName());}
        virtual void addChild(Node *child,const cocos2d::Vec2 &ratio, int z, int tag);
        virtual void addChild(Node *child, const cocos2d::Vec2 &ratio, int z, const string &name);
        
        virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags) override;
        
        inline cocos2d::Vec2 getEye() const {return eye;}
        inline void setEye(const cocos2d::Vec2 &eye) {this->eye = eye;}
        inline void setEyeX(float x) {this->eye.x = x;}
        inline void setEyeY(float y) {this->eye.y = y;}
        inline void changeEyeX(float dx) {this->eye.x += dx;}
        inline void changeEyeY(float dy) {this->eye.y += dy;}
        
        virtual cocos2d::Size getParallaxContentSize(const Node *child) const;
    public:
        CREATE_FUNC(ParallaxCamera);
    };
}

#endif /* defined(__GodRage_Endless_Revamp__ParallaxCamera__) */
