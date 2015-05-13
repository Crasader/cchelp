//
//  uiButtonLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"
#include "WidgetUtils.h"
#include "CocosGUI.h"

namespace ccHelp {
    void regisImageViewLayouts()
    {
        auto *scale9 = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!p.isBool())
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->setScale9Enabled(p.asBool());
        });
        GroupLayout::registerLayout("img-view-scale9-enabled", scale9);
        
        auto *setImage = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!p.isString())
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->loadTexture(p.asString());
        });
        GroupLayout::registerLayout("img-view-image", setImage);
        
        auto *setImageFrame = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            if (!p.isString())
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->loadTexture(p.asString(), ui::TextureResType::PLIST);
        });
        GroupLayout::registerLayout("img-view-image-frame", setImageFrame);
    }
}