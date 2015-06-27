//
//  SequenceActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/16/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class SequenceActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::Sequence* createAction(const FContext &ctx) const override;
    };
}
