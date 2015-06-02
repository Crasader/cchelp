//
//  ScaleToActionFactory.h
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/16/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class ScaleToActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::ScaleTo* createAction(const AFContext &ctx) const override;
    };
}
