//
//  InstantActionFactory.h
//  cchelp-action-factory-test_
//
//  Created by Vinova on 5/17/15.
//
//

#pragma once
#include "ActionFactory.h"
#include "hash_container/hmap.h"

namespace ccHelp {
    class InstantActionFactory : public ActionFactory
    {   
    private:
        static cocos2d::Map<string, cocos2d::CallFunc*> FUNC_CACHE;
        static cocos2d::Map<string, cocos2d::CallFuncN*> FUNCN_CACHE;
        
    public:
        virtual cocos2d::ActionInstant* createAction(const FContext &ctx) const override;
        
        bool containsAction(const string &ID) const;
        
        
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
        
        static void initCommonInstantActions();
    };
}