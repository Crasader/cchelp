//
//  LoadingBarLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#include "LayoutRegistration.h"
#include "CocosGUI.h"

namespace ccHelp {
    void regisLoadingBarLayouts()
    {
        auto *setProgress = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float f;
            if (!LayoutHelper::asFloat(p, f))
                return;
            
            ui::LoadingBar *loadBar = dynamic_cast<ui::LoadingBar*>(n);
            if (!loadBar)
                return;
            
            f = MIN(1, MAX(0, f));
            
            loadBar->setPercent(100 * f);
        });
        GroupLayout::registerLayout("loadingbar-progress", setProgress);
        
        auto *setTexture = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            ui::LoadingBar *loadBar = dynamic_cast<ui::LoadingBar*>(n);
            if (!loadBar)
                return;
            
            if (p.isString())
            {
                loadBar->loadTexture(p.asString());
            }
            else if (p.isObject())
            {
                if (!p.isMember("texture") || !p["texture"].isString())
                    return;
                
                string tex = p["texture"].asString();
                
                auto resType = ui::TextureResType::LOCAL;
                LayoutHelper::asUIResType(p["res-type"], resType);
                
                loadBar->loadTexture(tex, resType);
            }
        });
        GroupLayout::registerLayout("loadingbar-texture", setTexture);
        
        auto *enableScale9 = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!p.isBool())
                return;
            
            ui::LoadingBar *loadBar = dynamic_cast<ui::LoadingBar*>(n);
            if (!loadBar)
                return;
            
            loadBar->setScale9Enabled(p.asBool());
        });
        GroupLayout::registerLayout("loadingbar-scale9-enabled", enableScale9);
        
        auto *scale9Rect = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Rect r;
            if (!Json::type::deserialize(p, r))
                return;
            
            ui::LoadingBar *loadBar = dynamic_cast<ui::LoadingBar*>(n);
            if (!loadBar)
                return;
            
            loadBar->setCapInsets(r);
        });
        GroupLayout::registerLayout("loadingbar-scale9-rect", scale9Rect);
    }
}