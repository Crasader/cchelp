//
//  DoLayoutActionFactory.h
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/18/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class DoLayoutActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::CallFunc* createAction(const Parameter &p,
                                               const ActionFactoryContext &ctx) const override;
    };
}
