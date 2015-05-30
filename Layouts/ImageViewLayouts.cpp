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
            if (!p.isBool())
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->setScale9Enabled(p.asBool());
        });
        GroupLayout::registerLayout("img-view-scale9-enabled", scale9);
        
        auto *scale9Rect = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Rect r;
            if (!Json::type::deserialize(p, r))
                return;
            
            ui::ImageView *imgView = dynamic_cast<ui::ImageView*>(n);
            if (!imgView)
                return;
            
            imgView->setCapInsets(r);
        });
        GroupLayout::registerLayout("img-view-scale9-rect", scale9Rect);
        
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