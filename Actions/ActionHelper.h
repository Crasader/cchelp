//
//  ActionHelper.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "ActionFactory.h"
#include "hash_container/hmap.h"

namespace ccHelp {
    class ActionHelper
    {
    private:
        static hmap<string, ActionFactory*> FACTORIES;
        static hmap<string, ActionFactory::Parameter> CACHE;
        
    public:
        static Action* createAction(const ActionFactory::Parameter &p, const ActionContext &ctx);
        static Action* createActionByName(const string &actName, const ActionContext &ctx);
        static Action* createActionFromFile(const string &file, const ActionContext &ctx);
        static Action* createActionFromFile(const string &file,
                                            const string &actID,
                                            const ActionContext &ctx);
        
        static void loadAction(const string &actID, const ActionFactory::Parameter &p);
        inline static void loadActionFromFile(const string &fileName);
        
        static void regisFactory(const string &token, ActionFactory *factory);
        
    public:
        static void initAllActionFactories();
    };
}