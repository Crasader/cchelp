//
//  LayerColorLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#include "LayoutRegistration.h"

namespace ccHelp {
    void regisLayerColorLayouts()
    {
        auto *changeColor = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Color4B c4;
            if (!LayoutHelper::asColor4(p, c4))
                return;
            
            auto *layerColor = dynamic_cast<LayerColor *>(n);
            if (!layerColor)
                return;
            
            layerColor->setColor((Color3B) c4);
            layerColor->setOpacity(c4.a);
        });
        GroupLayout::registerLayout("layer-color-background", changeColor);
    }
}