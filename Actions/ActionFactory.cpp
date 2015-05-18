//
//  ActionFactory.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#include "ActionFactory.h"
#include "Utils.h"

namespace ccHelp {
    const ActionFactoryContext ActionFactoryContext::EMPTY {};
    
    ActionFactoryContext::ActionFactoryContext(const CallFuncFunction &completion)
    {
        Funcs["completion"] = completion;
    }
    
    CallFuncFunction ActionFactoryContext::getFunction(const string &name) const
    {
        string funcName = ccHelp::Utils::tolower(name);
        auto it = Funcs.find(funcName);
        if (it != Funcs.end())
            return it->second;
        
        return nullptr;
    }
}