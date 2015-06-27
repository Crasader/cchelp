//
//  AnimateActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class AnimateActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::Animate* createAction(const FContext &ctx) const override;
    };
}