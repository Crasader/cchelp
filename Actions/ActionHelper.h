//
//  ActionHelper.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "ActionFactory.h"
#include "hmap.h"

namespace ccHelp {
    class ActionHelper
    {
    private:
        static hmap<string, ActionFactory*> FACTORIES;
        
    public:
        static Action* createAction(const ActionFactory::Parameter &p, const ActionFactoryContext &ctx);
        static void regisFactory(const string &token, ActionFactory *factory);
        
    public:
        static void initAllActionFactories();
    };
}