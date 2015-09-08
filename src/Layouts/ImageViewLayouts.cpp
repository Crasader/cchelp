//
//  uiButtonLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"
#include "WidgetUtils.h"
#include "ui/CocosGUI.h"

namespace ccHelp {
    void regisImageViewLayouts()
    {
        auto *scale9 = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            bool scale9 = false;
            if (!p.get(scale9))
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->setScale9Enabled(scale9);
        });
        GroupLayout::registerLayout("img-view-scale9-enabled", scale9);
        
        auto *scale9Rect = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Rect r;
            if (!p.get(r))
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->setCapInsets(r);
        });
        GroupLayout::registerLayout("img-view-scale9-rect", scale9Rect);
        
        auto *setImage = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
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
                
                imgView->loadTexture(texture, resType);
            }
        });
        GroupLayout::registerLayout("img-view-image", setImage);
        
        auto *setImageFrame = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string texture;
            if (!p.get(texture))
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->loadTexture(texture, ui::TextureResType::PLIST);
        });
        GroupLayout::registerLayout("img-view-image-frame", setImageFrame);
    }
}