//
//  SequenceActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/16/15.
//
//

#include "SequenceActionFactory.h"
#include "ActionHelper.h"

namespace ccHelp {
    cocos2d::Sequence* SequenceActionFactory::createAction(const Parameter &par, const ActionFactoryContext &ctx) const
    {
        const auto &p = par["Actions"];
        if (!p.isArray() || p.size() < 2)
            return nullptr;
        
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(p.size());
        for (uint i = 0; i < p.size(); ++i)
        {
            auto *act = ActionHelper::createAction(p[i], ctx);
            if (!act)
                continue;
            
            auto *finAct = dynamic_cast<cocos2d::FiniteTimeAction*>(act);
            if (!finAct)
                continue;
            
            actions.pushBack(finAct);
        }
        
        return cocos2d::Sequence::create(actions);
    }
}