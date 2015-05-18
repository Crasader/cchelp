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

namespace ccHelp {
    hmap<string, ActionFactory*> ActionHelper::FACTORIES;
    hmap<string, ActionFactory::Parameter> ActionHelper::CACHE;
    
    Json::Value ActionHelper::jsonFromVsson(const vsson::VSSObject &vsson)
    {
        Json::Value js;
        
        std::function<void(const string&,
                           const vsson::VSSValue &)> func = [&js](const string &name,
                          const vsson::VSSValue &vssv)
        {
            if (name == "0")
            {
                js["Type"] = vssv.asString();
                return;
            }
            
            js[name] = vssv.asString();
        };
        
        vsson.foreach(func);
        
        return js;
    }
    
    cocos2d::Action* ActionHelper::createAction(const ActionFactory::Parameter &p, const ccHelp::ActionFactoryContext &ctx)
    {
        if (p.isObject())
        {
            CCASSERT(p["Type"].isString(), "Action object must contains Type field");
            
            string type = Utils::tolower(p["Type"].asString());
            auto it = FACTORIES.find(type);
            
            if (it != FACTORIES.end())
            {
                return it->second->createAction(p, ctx);
            }
            
            // it may be instant action
            auto *instantAction = InstantActionFactory::getInstance()->createAction(type, ctx);
            if (instantAction)
                return instantAction;
        }
        else if (p.isString())
        {
            vsson::VSSObject vsson = vsson::VSSParser::parse(p.asString());
            auto json = jsonFromVsson(vsson);
            return createAction(json, ctx);
        }
        
        return nullptr;
    }
    
    cocos2d::Action* ActionHelper::createAction(const string &actName, const ccHelp::ActionFactoryContext &ctx)
    {
        auto it = CACHE.find(actName);
        if (it == CACHE.end())
        {
            return createAction(it->first, ctx);
        }
        
        return nullptr;
    }
    
    cocos2d::Action* ActionHelper::createActionFromFile(const string &file, const ccHelp::ActionFactoryContext &ctx)
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
                                                        const ccHelp::ActionFactoryContext &ctx)
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
            auto json = jsonFromVsson(vsson);
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