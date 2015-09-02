//
//  NodePositioningLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"

namespace ccHelp {
    void regisNodePositioningLayouts()
    {
        auto *positioning = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isMember("x") && p["x"].isNumeric())
            {
                n->setPositionX(p["x"].asFloat());
            }
            
            if (p.isMember("y") && p["y"].isNumeric())
            {
                n->setPositionY(p["y"].asFloat());
            }
        });
        GroupLayout::registerLayout("position", positioning);
        
        /********************************************************************/
        
        auto *positioningX = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setPositionX(p.asFloat());
            }
        });
        GroupLayout::registerLayout("position-x", positioningX);
        
        // ----------------------------------------
        
        auto *positioningY = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setPositionY(p.asFloat());
            }
        });
        GroupLayout::registerLayout("position-y", positioningY);
        
        /********************************************************************/
        
        auto *positioningXPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float rate = 0;
            if (LayoutHelper::asFloat(p, rate))
            {
                n->setPositionX(n->getParent()->getContentSize().width * rate);
            }
        });
        GroupLayout::registerLayout("position-x-rate", positioningXPrc);
        
        // ----------------------------------------
        
        auto *positioningYPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float rate = 0;
            if (LayoutHelper::asFloat(p, rate))
            {
                n->setPositionY(n->getParent()->getContentSize().height * rate);
            }
        });
        GroupLayout::registerLayout("position-y-rate", positioningYPrc);
    }
    
    
    void regisNodeAlignLayouts()
    {
        /********************* ALIGN ABSOLUTELY *************************/
        
        auto *align = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isMember("left") && p["left"].isNumeric())
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(p["left"].asFloat());
            }
            
            if (p.isMember("bottom") && p["bottom"].isNumeric())
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(p["bottom"].asFloat());
            }
            
            if (p.isMember("right") && p["right"].isNumeric())
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX(n->getParent()->getContentSize().width - p["right"].asFloat());
            }
            
            if (p.isMember("top") && p["top"].isNumeric())
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY(n->getParent()->getContentSize().height - p["top"].asFloat());
            }
        });
        GroupLayout::registerLayout("align", align);
        
        auto *alignLeft = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(p.asFloat());
            }
        });
        GroupLayout::registerLayout("align-left", alignLeft);
        
        auto *alignBottom = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(p.asFloat());
            }
        });
        GroupLayout::registerLayout("align-bottom", alignBottom);
        
        auto *alignRight = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX(n->getParent()->getContentSize().width - p.asFloat());
            }
        });
        GroupLayout::registerLayout("align-right", alignRight);
        
        auto *alignTop = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY(n->getParent()->getContentSize().height - p.asFloat());
            }
        });
        GroupLayout::registerLayout("align-top", alignTop);
        
        
        auto *alignCenterX = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setAnchorPoint(Vec2(0.5, n->getAnchorPoint().y));
                n->setPositionX(p.asFloat());
            }
        });
        GroupLayout::registerLayout("align-center-x", alignCenterX);
        
        
        auto *alignCenterY = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0.5));
                n->setPositionY(p.asFloat());
            }
        });
        GroupLayout::registerLayout("align-center-y", alignCenterY);
    }
    
    void regisNodeAlignPrcLayouts()
    {
        /********************* ALIGN PERCENTAGE *************************/
        
        auto *alignPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f;
            
            if (p.isMember("left") && LayoutHelper::asFloat(p["left"], f))
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(f * n->getParent()->getContentSize().width);
            }
            
            if (p.isMember("bottom") && LayoutHelper::asFloat(p["bottom"], f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(f * n->getParent()->getContentSize().height);
            }
            
            if (p.isMember("right") && LayoutHelper::asFloat(p["right"], f))
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX(n->getParent()->getContentSize().width * (1 - f));
            }
            
            if (p.isMember("top") && LayoutHelper::asFloat(p["top"], f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY(n->getParent()->getContentSize().height * (1 - f));
            }
        });
        GroupLayout::registerLayout("align-rate", alignPrc);
        
        auto *alignLeftPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(f * n->getParent()->getContentSize().width);
            }
        });
        GroupLayout::registerLayout("align-left-rate", alignLeftPrc);
        
        auto *alignBottomPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(f * n->getParent()->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("align-bottom-rate", alignBottomPrc);
        
        auto *alignRightPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX((1 - f) * n->getParent()->getContentSize().width);
            }
        });
        GroupLayout::registerLayout("align-right-rate", alignRightPrc);
        
        auto *alignTopPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY((1 - f) * n->getParent()->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("align-top-rate", alignTopPrc);
        
        auto *alignCenterXPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(0.5, n->getAnchorPoint().y));
                n->setPositionX(f * n->getParent()->getContentSize().width);
            }
        });
        GroupLayout::registerLayout("align-center-x-rate", alignCenterXPrc);
        
        auto *alignCenterYPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0.5));
                n->setPositionY(f * n->getParent()->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("align-center-y-rate", alignCenterYPrc);
    }
}