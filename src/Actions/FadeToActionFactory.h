//
//  FadeToActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#pragma once
#include "ActionFactory.h"

namespace ccHelp {
    class FadeToActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::FadeTo* createAction(const AFContext &ctx) const override;
    };
}