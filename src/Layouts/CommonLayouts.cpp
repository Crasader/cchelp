//
//  CommonLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"
#include "Layoutable.h"
#include "Utils.h"

namespace ccHelp {
    void regisCommonLayouts()
    {
        // on layout
        auto *onLayout = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            auto *layoutable = dynamic_cast<Layoutable *>(n);
            if (!layoutable)
                return;
            
            layoutable->onLayout();
        });
        GroupLayout::registerLayout("begin-layout", onLayout);
        GroupLayout::registerLayout("start-layout", onLayout);
        GroupLayout::registerLayout("on-layout", onLayout);
        GroupLayout::registerLayout("do-layout", onLayout);
        GroupLayout::registerLayout("custom-layout", onLayout);
        GroupLayout::registerLayout("layout", onLayout);
        
        // visible
        auto *visible = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            bool isVisible = true;
            if (p.get(isVisible))
            {
                n->setVisible(isVisible);
            }
        });
        GroupLayout::registerLayout("visible", visible);
        
        // pause/resume
        auto *pause = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            bool isPause = true;
            if (!(p.get(isPause) || p.getJson().isNull()))
                return;
            
            if (!isPause)
            {
                ccHelp::Utils::resumeRecursively(n);
            }
            else
            {
                ccHelp::Utils::pauseRecursively(n);
            }
        });
        GroupLayout::registerLayout("pause", pause);
        
        // resume
        auto *resume = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            bool isResume = true;
            if (!(p.get(isResume) || p.getJson().isNull()))
                return;
            
            if (!isResume)
            {
                ccHelp::Utils::pauseRecursively(n);
            }
            else
            {
                ccHelp::Utils::resumeRecursively(n);
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
            bool enabled = true;
            if (p.get(enabled))
            {
                n->setCascadeColorEnabled(enabled);
                return;
            }
            
            string mode;
            if (p.get(enabled, 0, "enabled", "e", nullptr) && p.get(mode, 1, "mode", "m", nullptr))
            {
                mode = Utils::tolower(mode);
                
                if (mode == "node")
                {
                    n->setCascadeColorEnabled(enabled);
                }
                else if (mode == "allchilds")
                {
                    n->setCascadeColorEnabled(enabled);
                    for (auto *child : n->getChildren())
                    {
                        child->setCascadeColorEnabled(enabled);
                    }
                }
                else if (mode == "recursive")
                {
                    list<Node *> queue;
                    queue.push_back(n);
                    
                    while (!queue.empty())
                    {
                        auto *node = queue.front();
                        queue.pop_front();
                        
                        node->setCascadeColorEnabled(enabled);
                        for (auto *child : node->getChildren())
                        {
                            queue.push_back(child);
                        }
                    }
                }
            }
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
            bool enabled = true;
            if (!p.get(enabled))
                return;
            
            n->setCascadeOpacityEnabled(enabled);
        });
        GroupLayout::registerLayout("cascade-opacity", cascadingOpacity);
        
        // z
        auto *z_ordering = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            int z = 0;
            if (!p.get(z))
                return;
            
            n->setLocalZOrder(z);
        });
        GroupLayout::registerLayout("z-order", z_ordering);
        
        // tag
        auto *tagging = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            int tag = 0;
            if (!p.get(tag))
                return;
            
            n->setTag(tag);
        });
        GroupLayout::registerLayout("tag", tagging);
        
        // anchor
        auto *anchorLayout = new FunctionLayout([](Node *n, const Layout::Parameter &p){
            Vec2 anchor = n->getAnchorPoint();
            
            bool ret = p.get(anchor.x, 0, "x", nullptr);
            ret = p.get(anchor.y, 1, "y", nullptr) || ret;
            
            if (!ret)
            {
                string s;
                if (p.get(s))
                {
                    s = Utils::tolower(Utils::trim(s));
                    if (s == "top-left")
                        anchor = Vec2::ANCHOR_TOP_LEFT;
                    else if (s == "middle-left")
                        anchor = Vec2::ANCHOR_MIDDLE_LEFT;
                    else if (s == "bottom-left")
                        anchor = Vec2::ANCHOR_BOTTOM_LEFT;
                    else if (s == "top-middle")
                        anchor = Vec2::ANCHOR_MIDDLE_TOP;
                    else if (s == "middle-middle")
                        anchor = Vec2::ANCHOR_MIDDLE;
                    else if (s == "bottom-middle")
                        anchor = Vec2::ANCHOR_MIDDLE_BOTTOM;
                    else if (s == "top-right")
                        anchor = Vec2::ANCHOR_TOP_RIGHT;
                    else if (s == "middle-right")
                        anchor = Vec2::ANCHOR_MIDDLE_RIGHT;
                    else if (s == "bottom-right")
                        anchor = Vec2::ANCHOR_BOTTOM_RIGHT;
                }
            }
            
            n->setAnchorPoint(anchor);
        });
        GroupLayout::registerLayout("anchor", anchorLayout);
        
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