//
//  ActionFactoryRegistration.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/16/15.
//
//

#include "ActionFactoryRegistration.h"
#include "MoveByActionFactory.h"
#include "SequenceActionFactory.h"
#include "ScaleToActionFactory.h"

namespace ccHelp {
    
    void ActionHelper::initAllActionFactories()
    {
        regisCommonFactories();
    }
    
    void regisCommonFactories()
    {
        ActionHelper::regisFactory("moveby", new MoveByActionFactory);
        ActionHelper::regisFactory("sequence", new SequenceActionFactory);
        ActionHelper::regisFactory("scaleto", new ScaleToActionFactory);
    }
}