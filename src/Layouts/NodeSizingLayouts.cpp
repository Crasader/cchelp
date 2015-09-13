//
//  NodeSizingLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"
#include "Utils.h"

namespace ccHelp {
    void regisNodeSizingLayouts()
    {
        auto *resize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Size size = n->getContentSize();
            
            bool ret = p.get(size.width, 0, "width", "w", nullptr);
            ret = p.get(size.height, 1, "height", "h", nullptr) || ret;
            if (ret)
            {
                n->setContentSize(size);
            }
        });
        GroupLayout::registerLayout("size", resize);
        GroupLayout::registerLayout("resize", resize);
        
        auto *resizeDesignRate = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Size winSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
            Size size = n->getContentSize();
            
            Layout::Parameter pp;
            if (p.get(pp, 0, "width", "w", nullptr) && LayoutHelper::asFloat(pp, size.width))
            {
                size.width *= winSize.width;
            }
            
            if (p.get(pp, 1, "height", "h", nullptr) && LayoutHelper::asFloat(pp, size.height))
            {
                size.height *= winSize.height;
            }
            
            n->setContentSize(size);
        });
        GroupLayout::registerLayout("size-design-rate", resizeDesignRate);
        
        auto *resizeParentRate = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!n || !n->getParent())
                return;
            
            Size parentSize = n->getParent()->getContentSize();
            Size size = n->getContentSize();
            
            Layout::Parameter pp;
            if (p.get(pp, 0, "width", "w", nullptr) && LayoutHelper::asFloat(pp, size.width))
            {
                size.width *= parentSize.width;
            }
            
            if (p.get(pp, 1, "height", "h", nullptr) && LayoutHelper::asFloat(pp, size.height))
            {
                size.height *= parentSize.height;
            }
            
            n->setContentSize(size);
        });
        GroupLayout::registerLayout("size-parent-rate", resizeParentRate);
        
        auto *scale = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float s = 1.f;
            if (p.get(s))
            {
                n->setScale(s);
                return;
            }
            
            if (p.get(s, 0, "width", "w", "x", nullptr))
            {
                n->setScaleX(s);
            }
            
            if (p.get(s, 1, "height", "h", "y", nullptr))
            {
                n->setScaleY(s);
            }
        });
        GroupLayout::registerLayout("scale", scale);
        
        auto *scaleToSize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float s = 0.f;
            Layout::Parameter pp;
            if (p.get(pp, 0, "width", "w", "x", nullptr) && LayoutHelper::asFloat(pp, s))
            {
				n->setScaleX(s / n->getContentSize().width);
            }
            
            if (p.get(pp, 1, "height", "h", "y", nullptr) && LayoutHelper::asFloat(pp, s))
            {
				n->setScaleY(s / n->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("fit-size", scaleToSize);
        GroupLayout::registerLayout("scale-to-size", scaleToSize);
        
        auto *scaleToSizeBy = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Vec2 by = n->getContentSize();
            
            string sBy;
            if (p.get(sBy, 0, "by", nullptr))
            {
                sBy = Utils::tolower(sBy);
                if (sBy == "parent" && n->getParent())
                {
                    by = n->getParent()->getContentSize();
                }
                else if (sBy == "screen")
                {
                    by = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
                }
            }
            
            Layout::Parameter pp;
            float s = 0.f;
            if (p.get(pp, 0, "width", "w", "x", nullptr) && LayoutHelper::asFloat(pp, s))
            {
                n->setScaleX(s * by.x / n->getContentSize().width);
            }
            
            if (p.get(pp, 0, "width", "w", "x", nullptr) && LayoutHelper::asFloat(pp, s))
            {
                n->setScaleY(s * by.y / n->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("fit-size-by", scaleToSizeBy);
        GroupLayout::registerLayout("scale-to-size-by", scaleToSizeBy);
    }
}
