//
//  ResizeLayout.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#pragma once
#include "LayoutHelper.h"
#include <functional>

namespace ccHelp {
    class FunctionLayout : public Layout
    {
    public:
        typedef std::function<void(cocos2d::Node *node, const Layout::Parameter &par)> Function;
        
    private:
        Function func;
        
    public:
        inline FunctionLayout(Function f) :
            func(f)
        {
        }
        
        inline virtual void doLayout(cocos2d::Node *node, const Parameter &par) const
        {
            func(node, par);
        }
    };
}
