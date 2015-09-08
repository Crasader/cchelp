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
            float pos;
            if (p.get(pos, 0, "x", nullptr))
            {
                n->setPositionX(pos);
            }
            
            if (p.get(pos, 1, "y", nullptr))
            {
                n->setPositionY(pos);
            }
        });
        GroupLayout::registerLayout("position", positioning);
        
        /********************************************************************/
        
        auto *positioningX = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float pos;
            if (p.get(pos))
            {
                n->setPositionX(pos);
            }
        });
        GroupLayout::registerLayout("position-x", positioningX);
        
        // ----------------------------------------
        
        auto *positioningY = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float pos;
            if (p.get(pos))
            {
                n->setPositionY(pos);
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
        
        auto *alignLayout = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (p.get(align, 0, "left", nullptr))
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(align);
            }
            
            if (p.get(align, 1, "bottom", nullptr))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(align);
            }
            
            if (n->getParent() && p.get(align, 2, "right", nullptr))
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX(n->getParent()->getContentSize().width - align);
            }
            
            if (n->getParent() && p.get(align, 3, "top", nullptr))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY(n->getParent()->getContentSize().height - align);
            }
        });
        GroupLayout::registerLayout("align", alignLayout);
        
        auto *alignLeft = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (p.get(align))
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(align);
            }
        });
        GroupLayout::registerLayout("align-left", alignLeft);
        
        auto *alignBottom = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (p.get(align))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(align);
            }
        });
        GroupLayout::registerLayout("align-bottom", alignBottom);
        
        auto *alignRight = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (n->getParent() && p.get(align))
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX(n->getParent()->getContentSize().width - align);
            }
        });
        GroupLayout::registerLayout("align-right", alignRight);
        
        auto *alignTop = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (n->getParent() && p.get(align))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY(n->getParent()->getContentSize().height - align);
            }
        });
        GroupLayout::registerLayout("align-top", alignTop);
        
        
        auto *alignCenterX = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (p.get(align))
            {
                n->setAnchorPoint(Vec2(0.5, n->getAnchorPoint().y));
                n->setPositionX(align);
            }
        });
        GroupLayout::registerLayout("align-center-x", alignCenterX);
        
        
        auto *alignCenterY = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float align = 0;
            if (p.get(align))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0.5));
                n->setPositionY(align);
            }
        });
        GroupLayout::registerLayout("align-center-y", alignCenterY);
    }
    
    void regisNodeAlignPrcLayouts()
    {
        /********************* ALIGN PERCENTAGE *************************/
        
        auto *alignPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
            Layout::Parameter pp;
            float f = 0;
            if (p.get(pp, 0, "left", nullptr) && LayoutHelper::asFloat(pp, f))
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(f * n->getParent()->getContentSize().width);
            }
            
            if (p.get(pp, 1, "bottom", nullptr) && LayoutHelper::asFloat(pp, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(f * n->getParent()->getContentSize().height);
            }
            
            if (p.get(pp, 2, "right", nullptr) && LayoutHelper::asFloat(pp, f))
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX(n->getParent()->getContentSize().width * (1 - f));
            }
            
            if (p.get(pp, 3, "top", nullptr) && LayoutHelper::asFloat(pp, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY(n->getParent()->getContentSize().height * (1 - f));
            }
        });
        GroupLayout::registerLayout("align-rate", alignPrc);
        
        auto *alignLeftPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(0, n->getAnchorPoint().y));
                n->setPositionX(f * n->getParent()->getContentSize().width);
            }
        });
        GroupLayout::registerLayout("align-left-rate", alignLeftPrc);
        
        auto *alignBottomPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 0));
                n->setPositionY(f * n->getParent()->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("align-bottom-rate", alignBottomPrc);
        
        auto *alignRightPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(1, n->getAnchorPoint().y));
                n->setPositionX((1 - f) * n->getParent()->getContentSize().width);
            }
        });
        GroupLayout::registerLayout("align-right-rate", alignRightPrc);
        
        auto *alignTopPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(n->getAnchorPoint().x, 1));
                n->setPositionY((1 - f) * n->getParent()->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("align-top-rate", alignTopPrc);
        
        auto *alignCenterXPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
            float f = 0;
            if (LayoutHelper::asFloat(p, f))
            {
                n->setAnchorPoint(Vec2(0.5, n->getAnchorPoint().y));
                n->setPositionX(f * n->getParent()->getContentSize().width);
            }
        });
        GroupLayout::registerLayout("align-center-x-rate", alignCenterXPrc);
        
        auto *alignCenterYPrc = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n->getParent())
                return;
            
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