//
//  LayoutRegistration.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#pragma once
#include "LayoutHelper.h"
#include "cocos2d.h"
#include "jsoncpp/jsonserialization.h"
#include "FunctionLayout.h"
#include "GroupLayout.h"

USING_NS_CC;
using namespace std;

namespace ccHelp {
    // Node
    // Common
    void regisCommonLayouts();
    void regisAddChildLayouts();
    
    // Size
    void regisNodeSizingLayouts();
    // Positioning
    void regisNodePositioningLayouts();
    void regisNodeAlignLayouts();
    void regisNodeAlignPrcLayouts();
    
    // Layer color
    void regisLayerColorLayouts();
    
    // Label
    void regisLabelLayouts();
    
    // Widgets
    void regisWidgetLayouts();
    
    // Button
    void regisButtonLayouts();
    
    // Progress bar
    void regisLoadingBarLayouts();
}