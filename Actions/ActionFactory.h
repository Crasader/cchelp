//
//  ActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "Def.h"
#include "jsoncpp/json2/json.h"
#include "vsson/vsson.h"
#include "hmap.h"
#include "cocos2d.h"

using cocos2d::Action;
using std::string;

namespace ccHelp {
    typedef std::function<void()> CallFuncFunction;
    typedef std::function<void(cocos2d::Node*)> CallFuncNFunction;
    
    class ActionFactoryContext
    {
    private:
        hmap<string, CallFuncFunction> Funcs;
        hmap<string, CallFuncNFunction> FuncNs;
        
    public:
        ActionFactoryContext() = default;
        ActionFactoryContext(const ActionFactoryContext &ctx) = default;
        ActionFactoryContext& operator=(const ActionFactoryContext &ctx) = default;
        
        ActionFactoryContext(const CallFuncFunction &completion);
        
        CallFuncFunction getFunction(const string &name) const;
        
        static const ActionFactoryContext EMPTY;
    };
    
    class ActionFactory
    {
    public:
        typedef Json::Value Parameter;
        typedef vsson::VSSObject ShortcutParameter;
        
        virtual Action* createAction(const Parameter &p, const ActionFactoryContext &ctx) const = 0;
    };
}
