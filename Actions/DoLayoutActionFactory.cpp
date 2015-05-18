//
//  DoLayoutActionFactory.cpp
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/18/15.
//
//

#include "DoLayoutActionFactory.h"
#include "jsonserialization.h"
#include "Layouts/LayoutHelper.h"

namespace ccHelp {
    
    cocos2d::CallFunc* DoLayoutActionFactory::createAction(const Parameter &p, const ActionFactoryContext &ctx) const
    {
        return cocos2d::CallFuncN::create([p](cocos2d::Node *n) {
            ccHelp::LayoutHelper::applyJson(n, p["Layout"]);
        });
    }
}