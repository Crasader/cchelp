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
    hmap<string, Action*> ActionHelper::CACHE;
    
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
    
    void ActionHelper::loadAction(const string &actID, const ActionFactory::Parameter &p, const ccHelp::ActionFactoryContext &ctx)
    {
        if (p.isObject())
        {
            if (!actID.empty() && p["Type"].isString())
            {
                // p contains Type field, p is an action
                auto *act = createAction(p, ctx);
                if (act)
                {
                    CACHE[actID] = act;
                }
                return;
            }
            
            // p doesn't contains type field, p may be an dictionary of actions
            for (Json::ValueIterator it = p.begin(); it != p.end(); ++it)
            {
                loadAction(it.key().asString(), *it, ctx);
            }
            return;
        }
        
        if (p.isArray())
        {
            // p may be array of actions
            for (uint i = 0; i < p.size(); ++i)
            {
                loadAction(p[i], ctx);
            }
        }
    }
    
    void ActionHelper::loadAction(const ActionFactory::Parameter &p, const ccHelp::ActionFactoryContext &ctx)
    {
        string actID;
        if (p["ID"].isString())
        {
            actID = p["ID"].asString();
        }
        
        loadAction(actID, p, ctx);
    }
    
    void ActionHelper::loadActionFromFile(const string &fileName,
                                          const ActionFactoryContext &ctx)
    {
        loadAction(Utils::jsonFromFile(fileName), ctx);
    }
    
    Action* ActionHelper::getAction(const string &actID)
    {
        auto it = CACHE.find(actID);
        if (it == CACHE.end())
            return nullptr;
        
        return it->second->clone();
    }
}