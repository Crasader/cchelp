//
//  MoveByActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/16/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class MoveByActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::MoveBy* createAction(const FContext &ctx) const override;
    };
}
