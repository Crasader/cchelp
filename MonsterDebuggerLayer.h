//
//  MonsterDebuggerLayer.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/18/15.
//
//

#pragma once
#include "cocos2d.h"
#include "hash_container/hset.h"
#include "hash_container/hmap.h"

namespace ccHelp {

    class MonsterDebuggerLayer : public cocos2d::Node
    {
    private:
        cocos2d::DrawNode *pen;
        cocos2d::Vec2 mousePosition;
        bool _dirty;
        
        hset<cocos2d::Node *> disabledNodes;
        hset<cocos2d::Node *> recursivelyDisabledNodes;
        
    public:
        virtual bool init() override;
        virtual void update(float dt) override;
        
        virtual void setParent(Node *parent) override;
        
    private:
        Node* findNode();
        bool containsMouse(Node *n);
        
        void clearAllDisableNode();
        
    public:
        CREATE_FUNC(MonsterDebuggerLayer);
        
        friend class MDebugger;
    };
    
    class MDebugger
    {
    private:
        static cocos2d::Map<cocos2d::Scene*, MonsterDebuggerLayer*> DEBUGGERS;
        friend class MonsterDebuggerLayer;
        
    public:
        static void disable(cocos2d::Node *n);
        static void enable(cocos2d::Node *n);
        
        static void disableRecursively(cocos2d::Node *n);
        static void enableRecursively(cocos2d::Node *n);
    };
}
