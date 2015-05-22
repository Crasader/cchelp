//
//  DelayActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class DelayActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::DelayTime* createAction(const AFContext &ctx) const override;
    };
}