//
//  MonsterDebuggerLayer.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/18/15.
//
//

#include "MonsterDebuggerLayer.h"
#include <limits>
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace std;

namespace ccHelp {
    bool MonsterDebuggerLayer::init()
    {
        if (!Node::init())
            return false;
        
        this->setLocalZOrder(std::numeric_limits<int>::max());
        
        this->pen = DrawNode::create();
        addChild(pen);
        
        _dirty = false;
        auto *label = cocos2d::Label::create();
        label->setAlignment(TextHAlignment::RIGHT, TextVAlignment::TOP);
        label->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
        
        auto winSize = Director::getInstance()->getWinSize();
        label->setPosition(winSize);
        addChild(label);
        
        auto *mouseListener = cocos2d::EventListenerMouse::create();
        mouseListener->onMouseMove = [=](Event *e) {
            mousePosition = dynamic_cast<EventMouse*>(e)->getLocation();
            mousePosition.y = winSize.height - mousePosition.y;
            _dirty = true;
            
            label->setString(StringUtils::format("x: %.2f, y: %.2f", mousePosition.x, mousePosition.y));
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
        
        this->scheduleUpdate();
        
        return true;
    }
    
    void MonsterDebuggerLayer::update(float dt)
    {
        pen->clear();
        
        auto winSize = Director::getInstance()->getWinSize();
        if (mousePosition.x < 0 || mousePosition.y < 0 || mousePosition.x >= winSize.width || mousePosition.y >= winSize.height)
            return;
        
        auto node = findNode();
        if (!node)
            return;
        
        auto leftBottom = node->convertToWorldSpace(Vec2::ZERO);
        auto rightTop = node->convertToWorldSpace(node->getContentSize());
        
        pen->drawRect(leftBottom, rightTop, Color4F::RED);
    }
    
    Node* MonsterDebuggerLayer::findNode()
    {
        struct Data
        {
            Data(Node *n, int d)
            : node(n), deep(d) {
                
            }
            
            Node *node;
            int deep;
        };
        
        struct _Widget : public ui::Widget
        {
        public:
            const Vector<Node *>& getProtectedChildren() const
            {
                return this->_protectedChildren;
            }
        };
        
        list<Data> stack;
        stack.push_back({this->getScene(), 0});
        
        Node *chosenNode;
        int maxDeep = -1;
        
        while (!stack.empty())
        {
            auto data = stack.back();
            stack.pop_back();
            
            bool isDisabled = (disabledNodes.find(data.node) != disabledNodes.end());
            bool isRecDisabled = (recursivelyDisabledNodes.find(data.node) != recursivelyDisabledNodes.end());
            
            if (!isDisabled && !isRecDisabled &&
                data.deep >= maxDeep &&
                containsMouse(data.node))
            {
                chosenNode = data.node;
                maxDeep = data.deep;
            }
            
            if (!isRecDisabled)
            {
                for (auto *child : data.node->getChildren())
                {
                    stack.push_back({child, data.deep + 1});
                }
                
                if (auto *widget = dynamic_cast<ui::Widget*>(data.node))
                {
                    for (auto *child : ((_Widget *) widget)->getProtectedChildren())
                    {
                        stack.push_back({child, data.deep + 1});
                    }
                }
            }
        }
        
        return chosenNode;
    }
    
    bool MonsterDebuggerLayer::containsMouse(cocos2d::Node *node)
    {
        if (!node)
            return false;
        
        auto localMousePos = node->convertToNodeSpace(mousePosition);
        
        return ((localMousePos.x >= 0) &&
                (localMousePos.y >= 0) &&
                (localMousePos.x <= node->getContentSize().width) &&
                (localMousePos.y <= node->getContentSize().height));
    }
    
    void MonsterDebuggerLayer::setParent(Node *parent)
    {
        Scene *oldScene = this->getScene();
        
        Node::setParent(parent);
        
        Scene *newScene = this->getScene();
        if (oldScene == newScene)
            return;
        
        if (oldScene)
        {
            MDebugger::DEBUGGERS.erase(oldScene);
            clearAllDisableNode();
        }
        
        if (newScene)
        {
            MDebugger::DEBUGGERS.insert(newScene, this);
        }
    }
    
    void MonsterDebuggerLayer::clearAllDisableNode()
    {
        this->disabledNodes.clear();
        this->recursivelyDisabledNodes.clear();
    }
    
    Map<Scene*, MonsterDebuggerLayer*> MDebugger::DEBUGGERS;
    
    void MDebugger::disable(cocos2d::Node *n)
    {
        auto it = DEBUGGERS.find(n->getScene());
        if (it != DEBUGGERS.end())
        {
            it->second->disabledNodes.insert(n);
        }
    }
    
    void MDebugger::enable(cocos2d::Node *n)
    {
        auto it = DEBUGGERS.find(n->getScene());
        if (it != DEBUGGERS.end())
        {
            it->second->disabledNodes.erase(n);
        }
    }
    
    void MDebugger::disableRecursively(cocos2d::Node *n)
    {
        auto it = DEBUGGERS.find(n->getScene());
        if (it != DEBUGGERS.end())
        {
            it->second->recursivelyDisabledNodes.insert(n);
        }
    }
    
    void MDebugger::enableRecursively(cocos2d::Node *n)
    {
        auto it = DEBUGGERS.find(n->getScene());
        if (it != DEBUGGERS.end())
        {
            it->second->recursivelyDisabledNodes.erase(n);
        }
    }
}