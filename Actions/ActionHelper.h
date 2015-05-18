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
        static hmap<string, ActionFactory::Parameter> CACHE;
        
        static Json::Value jsonFromVsson(const vsson::VSSObject &vsson);
        
    public:
        static Action* createAction(const ActionFactory::Parameter &p, const ActionFactoryContext &ctx);
        static Action* createAction(const string &actName, const ActionFactoryContext &ctx);
        static Action* createActionFromFile(const string &file, const ActionFactoryContext &ctx);
        static Action* createActionFromFile(const string &file,
                                            const string &actID,
                                            const ActionFactoryContext &ctx);
        
        static void loadAction(const string &actID, const ActionFactory::Parameter &p);
        inline static void loadActionFromFile(const string &fileName);
        
        static void regisFactory(const string &token, ActionFactory *factory);
        
    public:
        static void initAllActionFactories();
    };
}