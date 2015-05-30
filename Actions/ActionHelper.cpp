//
//  ActionHelper.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#include "ActionHelper.h"
#include "InstantActionFactory.h"
#include "Utils.h"
#include <vsson/vsson.h>

namespace ccHelp {
    hmap<string, ActionFactory*> ActionHelper::FACTORIES;
    hmap<string, ActionFactory::Parameter> ActionHelper::CACHE;
    
    cocos2d::Action* ActionHelper::createAction(const ActionFactory::Parameter &p, const ActionContext &ctx)
    {
        cocos2d::Action *action = nullptr;
        if (p.isObject())
        {
            bool valid = false;
            string type;
            
            if (p["Type"].isString())
            {
                type = p["Type"].asString();
                valid = true;
            }
            else if (p["0"].isString())
            {
                type = p["0"].asString();
                valid = true;
            }
            
            
            CCASSERT(valid, "Action object must contains Type field");
            
            type = Utils::tolower(type);
            auto it = FACTORIES.find(type);
            
            if (it != FACTORIES.end())
            {
                action = it->second->createAction(AFContext(ctx, p));
            }
            else
            {
                // it may be instant action
                action = InstantActionFactory::getInstance()->createAction(AFContext(ctx, p));
            }
            
        }
        else if (p.isString())
        {
            vsson::VSSObject vsson = vsson::VSSParser::parse(p.asString());
            auto json = Utils::jsonFromVsson(vsson);
            action = createAction(json, ctx);
        }

#if COCOS2D_DEBUG <= 0
        // no debug return safe action
        if (!action)
        {
            return cocos2d::CallFunc::create([](){});
        }
#endif
        return action;
    }
    
    cocos2d::Action* ActionHelper::createActionByName(const string &actName, const ActionContext &ctx)
    {
        auto it = CACHE.find(actName);
        if (it == CACHE.end())
        {
            return createAction(it->first, ctx);
        }
        
        return nullptr;
    }
    
    cocos2d::Action* ActionHelper::createActionFromFile(const string &file, const ActionContext &ctx)
    {
        auto it = CACHE.find(file);
        if (it == CACHE.end())
        {
            loadActionFromFile(file);
            it = CACHE.find(file);
        }
        
        if (it != CACHE.end())
        {
            return createAction(it->second, ctx);
        }
        
        return nullptr;
    }
    
    cocos2d::Action* ActionHelper::createActionFromFile(const string &file,
                                                        const string &actID,
                                                        const ActionContext &ctx)
    {
        auto it = CACHE.find(actID);
        if (it == CACHE.end())
        {
            loadActionFromFile(file);
            it = CACHE.find(actID);
        }
        
        if (it != CACHE.end())
        {
            return createAction(it->second, ctx);
        }
        
        return nullptr;
    }
    
    void ActionHelper::regisFactory(const string &token, ccHelp::ActionFactory *factory)
    {
        FACTORIES[token] = factory;
    }
    
    void ActionHelper::loadAction(const string &actID, const ActionFactory::Parameter &p)
    {
        if (p.isObject())
        {
            if (p["Type"].isString())
            {
                string type = Utils::tolower(p["Type"].asString());
                auto it = FACTORIES.find(type);
                
                if (it != FACTORIES.end())
                {
                    CACHE[actID] = p;
                    return;
                }
                
                // it may be instant actiom
                if (InstantActionFactory::getInstance()->containsAction(type))
                {
                    CACHE[actID] = p;
                }
            }
            else
            {
                for (Json::ValueIterator it = p.begin(); it != p.end(); ++it)
                {
                    loadAction(actID + "." + it.key().asString(), *it);
                }
            }
        }
        else if (p.isString())
        {
            vsson::VSSObject vsson = vsson::VSSParser::parse(p.asString());
            auto json = Utils::jsonFromVsson(vsson);
            loadAction(actID, json);
        }
    }
    
    void ActionHelper::loadActionFromFile(const string &fileName)
    {
        auto js = ccHelp::Utils::jsonFromFile(fileName);
        if (js["Type"].isString())
        {
            loadAction(fileName, js);
        }
        else
        {
            for (Json::ValueIterator ite = js.begin(); ite != js.end(); ++ite)
            {
                loadAction(ite.key().asString(), *ite);
            }
        }
    }
}