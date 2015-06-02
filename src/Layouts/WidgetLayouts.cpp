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
            if (!p.isBool())
                return;
            
            ui::Widget *widget = dynamic_cast<ui::Widget*>(n);
            if (!widget)
                return;
            
            widget->ignoreContentAdaptWithSize(p.asBool());
        });
        GroupLayout::registerLayout("widget-ignore-adapt-size", ignoreAdaptSize);
        
        auto *autosize = new FunctionLayout([ignoreAdaptSize](Node *n, const Layout::Parameter &p) {
            if (!p.isBool())
                return;
            ignoreAdaptSize->doLayout(n, Json::Value(!p.asBool()));
        });
        GroupLayout::registerLayout("widget-autosize", autosize);
    }
}
