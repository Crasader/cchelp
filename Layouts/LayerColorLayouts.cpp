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
            // haven't supported yet!
        });
        GroupLayout::registerLayout("layer-color-background", changeColor);
    }
}