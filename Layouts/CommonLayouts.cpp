//
//  CommonLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"
#include "Utils.h"

namespace vin {
    void regisCommonLayouts()
    {
        // visible
        auto *visible = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (p.isBool())
            {
                n->setVisible(p.asBool());
            }
        });
        GroupLayout::registerLayout("visible", visible);
        
        // pause/resume
        auto *pause = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (!(p.isBool() || p.isNull()))
                return;
            
            if (p.isNull() || p.asBool())
            {
                vin::Utils::pauseRecursively(n);
            }
            else
            {
                vin::Utils::resumeRecursively(n);
            }
        });
        GroupLayout::registerLayout("pause", pause);
        
        // resume
        auto *resume = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (!(p.isBool() || p.isNull()))
                return;
            
            if (p.isNull() || p.asBool())
            {
                vin::Utils::resumeRecursively(n);
            }
            else
            {
                vin::Utils::pauseRecursively(n);
            }
        });
        GroupLayout::registerLayout("resume", resume);
        
        // color
        auto *coloring = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            Color3B c;
            if (!LayoutHelper::asColor3(p, c))
                return;
            
            n->setColor(c);
        });
        GroupLayout::registerLayout("color", coloring);
        
        // color
        auto *cascadingColor = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (!p.isBool())
                return;
            
            n->setCascadeColorEnabled(p.asBool());
        });
        GroupLayout::registerLayout("cascade-color", cascadingColor);
        
        // opacity
        auto *opacity = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            float f;
            if (!LayoutHelper::asFloat(p, f))
                return;
            
            n->setOpacity((GLubyte) (f * 0xff));
        });
        GroupLayout::registerLayout("opacity", opacity);
        
        // color
        auto *cascadingOpacity = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (!p.isBool())
                return;
            
            n->setCascadeOpacityEnabled(p.asBool());
        });
        GroupLayout::registerLayout("cascade-opacity", cascadingOpacity);
        
        // z
        auto *z_ordering = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (!p.isInt())
                return;
            
            n->setLocalZOrder(p.asInt());
        });
        GroupLayout::registerLayout("z-order", z_ordering);
        
        // tag
        auto *tagging = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            if (!p.isInt())
                return;
            
            n->setTag(p.asInt());
        });
        GroupLayout::registerLayout("tag", tagging);
        
        // anchor
        auto *anchor = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            Vec2 anchor = n->getAnchorPoint();
            float f;
            if (LayoutHelper::asFloat(p["x"], f))
            {
                anchor.x = f;
            }
            
            if (LayoutHelper::asFloat(p["y"], f))
            {
                anchor.y = f;
            }
            
            n->setAnchorPoint(anchor);
        });
        GroupLayout::registerLayout("anchor", anchor);
        
        // anchor x
        auto *anchorX = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            Vec2 anchor = n->getAnchorPoint();
            if (LayoutHelper::asFloat(p, anchor.x))
            {
                n->setAnchorPoint(anchor);
            }
        });
        GroupLayout::registerLayout("anchor-x", anchorX);
        
        // anchor y
        auto *anchorY = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            Vec2 anchor = n->getAnchorPoint();
            if (LayoutHelper::asFloat(p, anchor.y))
            {
                n->setAnchorPoint(anchor);
            }
        });
        GroupLayout::registerLayout("anchor-y", anchorY);
    }
}