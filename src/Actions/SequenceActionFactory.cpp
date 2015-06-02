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
    cocos2d::Sequence* SequenceActionFactory::createAction(const AFContext &ctx) const
    {
        Json::Value jsActions;
        if (!ctx.getField("Actions", jsActions))
            return nullptr;
        
        if (!jsActions.isArray() || jsActions.size() < 2)
            return nullptr;
        
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(jsActions.size());
        for (uint i = 0; i < jsActions.size(); ++i)
        {
            auto *act = ActionHelper::createAction(jsActions[i], ctx.getContext());
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