//
//  DoLayoutActionFactory.cpp
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/18/15.
//
//

#include "DoLayoutActionFactory.h"
#include "jsoncpp/jsonserialization.h"
#include "Layouts/LayoutHelper.h"

namespace ccHelp {
    
    cocos2d::CallFunc* DoLayoutActionFactory::createAction(const AFContext &ctx) const
    {
        Json::Value layout;
        if (!ctx.getField("Layout", layout))
            return nullptr;
        
        return cocos2d::CallFuncN::create([layout](cocos2d::Node *n) {
            ccHelp::LayoutHelper::applyJson(n, layout);
        });
    }
}