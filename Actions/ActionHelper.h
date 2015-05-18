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
        static hmap<string, Action*> CACHE;
        
    public:
        static Action* createAction(const ActionFactory::Parameter &p, const ActionFactoryContext &ctx);
        static void regisFactory(const string &token, ActionFactory *factory);
        
        static void loadAction(const string &actID, const ActionFactory::Parameter &p, const ActionFactoryContext &ctx);
        static void loadAction(const ActionFactory::Parameter &p, const ActionFactoryContext &ctx);
        inline static void loadActionFromFile(const string &fileName,
                                              const ActionFactoryContext &ctx);
        
        static Action* getAction(const string &actID);
    public:
        static void initAllActionFactories();
    };
}