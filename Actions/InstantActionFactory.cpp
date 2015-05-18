//
//  InstantActionFactory.cpp
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/17/15.
//
//

#include "InstantActionFactory.h"

namespace ccHelp {
    InstantActionFactory* InstantActionFactory::INSTANCE = new InstantActionFactory;
    cocos2d::Map<string, cocos2d::CallFunc*> InstantActionFactory::FUNC_CACHE;
    cocos2d::Map<string, cocos2d::CallFuncN*> InstantActionFactory::FUNCN_CACHE;
    
    cocos2d::ActionInstant* InstantActionFactory::createAction(const ActionFactory::Parameter &p, const ccHelp::ActionFactoryContext &ctx) const
    {
        if (p.isString())
        {
            // this is shortcut
            string ID = p.asString();
            
            auto fsIte = FUNC_CACHE.find(ID);
            if (fsIte != FUNC_CACHE.end())
            {
                return fsIte->second->clone();
            }
            
            auto fnsIte = FUNCN_CACHE.find(ID);
            if (fnsIte != FUNCN_CACHE.end())
            {
                return fnsIte->second->clone();
            }
            
            // or return call back from context
        }
        
        return nullptr;
    }
    
    void InstantActionFactory::addFunctionShortcut(string ID, CallFuncFunction func)
    {
        FUNC_CACHE.insert(ID, cocos2d::CallFunc::create(func));
    }
    
    void InstantActionFactory::addFunctionNShortcut(string ID, CallFuncNFunction func)
    {
        FUNCN_CACHE.insert(ID, cocos2d::CallFuncN::create(func));
    }
}