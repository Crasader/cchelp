//
//  NodeSizingLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"

namespace ccHelp {
    void regisNodeSizingLayouts()
    {
        auto *resize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Size size = n->getContentSize();
            
            if (p.isMember("width"))
            {
                size.width = p["width"].asFloat();
            }
            
            if (p.isMember("height"))
            {
                size.height = p["height"].asFloat();
            }
            
            n->setContentSize(size);
        });
        GroupLayout::registerLayout("size", resize);
        GroupLayout::registerLayout("resize", resize);
        
        auto *resizeDesignRate = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Size winSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
            Size size = n->getContentSize();
            
            if (LayoutHelper::asFloat(p["width"], size.width))
            {
                size.width *= winSize.width;
            }
            
            if (LayoutHelper::asFloat(p["height"], size.height))
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
            
            if (LayoutHelper::asFloat(p["width"], size.width))
            {
                size.width *= parentSize.width;
            }
            
            if (LayoutHelper::asFloat(p["height"], size.height))
            {
                size.height *= parentSize.height;
            }
            
            n->setContentSize(size);
        });
        GroupLayout::registerLayout("size-parent-rate", resizeParentRate);
        
        auto *scale = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isNumeric())
            {
                n->setScale(p.asFloat());
                return;
            }
            
            float scale = 1;
            
            string xField = LayoutHelper::chooseMember(p, 2, "width", "x");
            if (!xField.empty() && LayoutHelper::asFloat(p[xField], scale))
            {
                n->setScaleX(scale);
            }
            
            string yField = LayoutHelper::chooseMember(p, 2, "height", "y");
            if (!yField.empty() && LayoutHelper::asFloat(p[yField], scale))
            {
                n->setScaleY(scale);
            }
        });
        GroupLayout::registerLayout("scale", scale);
        
        auto *scaleToSize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (p.isMember("width") && p["width"].isNumeric())
            {
				n->setScaleX(p["width"].asFloat() / n->getContentSize().width);
            }
            
            if (p.isMember("height") && p["height"].isNumeric())
            {
				n->setScaleY(p["height"].asFloat() / n->getContentSize().height);
            }
        });
        GroupLayout::registerLayout("fit-size", scaleToSize);
        GroupLayout::registerLayout("scale-to-size", scaleToSize);
    }
}
