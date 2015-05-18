//
//  InstantActionFactory.h
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/17/15.
//
//

#pragma once
#include "ActionFactory.h"
#include "hmap.h"

namespace ccHelp {
    class InstantActionFactory : public ActionFactory
    {
    public:
        typedef std::function<void()> CallFuncFunction;
        typedef std::function<void(cocos2d::Node*)> CallFuncNFunction;
        
    private:
        static cocos2d::Map<string, cocos2d::CallFunc*> FUNC_CACHE;
        static cocos2d::Map<string, cocos2d::CallFuncN*> FUNCN_CACHE;
        
    public:
        virtual cocos2d::ActionInstant* createAction(const ActionFactory::Parameter &p,
                                                     const ActionFactoryContext &ctx) const override;
        virtual cocos2d::ActionInstant* createAction(const ShortcutParameter &p,
                                                     const ActionFactoryContext &ctx) const override;
        
        
        static void addFunctionShortcut(string ID,
                                        CallFuncFunction func);
        static void addFunctionNShortcut(string ID,
                                         CallFuncNFunction func);
    
    // singleton
    private:
        static InstantActionFactory* INSTANCE;
        
    public:
        inline static InstantActionFactory* getInstance()
        {
            return INSTANCE;
        }
    };
}