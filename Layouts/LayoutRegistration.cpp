//
//  LayoutRegistration.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#include "LayoutRegistration.h"

namespace vin {
    
    class Registrator
    {
    public:
        STATIC_CONSTRUCTOR_DECLARE(Registrator);
    };
    
    STATIC_CONSTRUCTOR_IMPL(Registrator)
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
