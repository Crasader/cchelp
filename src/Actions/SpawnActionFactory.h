//
//  SpawnAction.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#include "ActionFactory.h"

namespace ccHelp {
    class SpawnActionFactory : public ActionFactory
    {
    public:
        virtual cocos2d::Spawn* createAction(const AFContext &ctx) const override;
    };
}