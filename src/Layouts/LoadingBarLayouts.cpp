//
//  LoadingBarLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#include "LayoutRegistration.h"
#include "ui/CocosGUI.h"

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
            
            string texture;
            if (p.get(texture, 0, "texture", "tex", nullptr))
            {
                auto resType = ui::TextureResType::LOCAL;
                string res;
                if (p.get(res, 1, "res-type", "res", nullptr))
                {
                    LayoutHelper::asUIResType(res, resType);
                }
                
                loadBar->loadTexture(texture, resType);
            }
        });
        GroupLayout::registerLayout("loadingbar-texture", setTexture);
        
        auto *enableScale9 = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            bool enabled = true;
            if (!p.get(enabled))
                return;
            
            ui::LoadingBar *loadBar = dynamic_cast<ui::LoadingBar*>(n);
            if (!loadBar)
                return;
            
            loadBar->setScale9Enabled(enabled);
        });
        GroupLayout::registerLayout("loadingbar-scale9-enabled", enableScale9);
        
        auto *scale9Rect = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Rect r;
            if (!p.get(r))
                return;
            
            ui::LoadingBar *loadBar = dynamic_cast<ui::LoadingBar*>(n);
            if (!loadBar)
                return;
            
            loadBar->setCapInsets(r);
        });
        GroupLayout::registerLayout("loadingbar-scale9-rect", scale9Rect);
    }
}