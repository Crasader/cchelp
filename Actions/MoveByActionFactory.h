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
        virtual cocos2d::MoveBy* createAction(const Parameter &p, const ActionFactoryContext &ctx) const override;
        virtual cocos2d::MoveBy* createAction(const ShorcutParameter &p,
                                              const ActionFactoryContext &ctx) const override;
    };
}
