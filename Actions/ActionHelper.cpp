//
//  ActionHelper.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#include "ActionHelper.h"
#include "Utils.h"

namespace ccHelp {
    hmap<string, ActionFactory*> ActionHelper::FACTORIES;
    
    cocos2d::Action* ActionHelper::createAction(const ActionFactory::Parameter &p, const ccHelp::ActionFactoryContext &ctx)
    {
        if (p.isObject() && p["Type"].isString())
        {
            string type = Utils::tolower(p["Type"].asString());
            auto it = FACTORIES.find(type);
            
            if (it != FACTORIES.end())
            {
                return it->second->createAction(p, ctx);
            }
        }
        
        return nullptr;
    }
    
    void ActionHelper::regisFactory(const string &token, ccHelp::ActionFactory *factory)
    {
        FACTORIES[token] = factory;
    }
}