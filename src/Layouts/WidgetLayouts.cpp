//
//  WidgetLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#include "LayoutRegistration.h"

namespace ccHelp {
    void regisWidgetLayouts()
    {
        auto *ignoreAdaptSize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            bool ignore = false;
            if (!p.get(ignore))
                return;
            
            ui::Widget *widget = dynamic_cast<ui::Widget*>(n);
            if (!widget)
                return;
            
            widget->ignoreContentAdaptWithSize(ignore);
        });
        GroupLayout::registerLayout("widget-ignore-adapt-size", ignoreAdaptSize);
        
        auto *autosize = new FunctionLayout([ignoreAdaptSize](Node *n, const Layout::Parameter &p) {
            bool autosize = true;
            if (!p.get(autosize))
                return;
            
            ui::Widget *widget = dynamic_cast<ui::Widget*>(n);
            if (!widget)
                return;
            
            widget->ignoreContentAdaptWithSize(!autosize);
        });
        GroupLayout::registerLayout("widget-autosize", autosize);
    }
}
