//
//  LayoutRegistration.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#include "LayoutRegistration.h"

namespace ccHelp {
    void LayoutHelper::initAllLayouts()
    {
        GroupLayout::registerLayout("group", GroupLayout::getInstance());
        
        regisCommonLayouts();
        regisAddChildLayouts();
        
        regisNodeSizingLayouts();
        
        regisNodePositioningLayouts();
        regisNodeAlignLayouts();
        regisNodeAlignPrcLayouts();
        
        regisLayerColorLayouts();
        
        regisWidgetLayouts();
        regisButtonLayouts();
        regisLabelLayouts();
        regisLoadingBarLayouts();
    }
}
