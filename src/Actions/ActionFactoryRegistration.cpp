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
#include "InstantActionFactory.h"
#include "PlaySoundActionFactory.h"
#include "DoLayoutActionFactory.h"
#include "SpawnActionFactory.h"
#include "FadeToActionFactory.h"
#include "DelayActionFactory.h"
#include "AnimateActionFactory.h"

namespace ccHelp {
    
    void ActionHelper::initAllActionFactories()
    {
        regisCommonFactories();
    }
    
    void regisCommonFactories()
    {
        InstantActionFactory::initCommonInstantActions();
        
        ActionHelper::regisFactory("moveby", new MoveByActionFactory);
        ActionHelper::regisFactory("sequence", new SequenceActionFactory);
        ActionHelper::regisFactory("spawn", new SpawnActionFactory);
        ActionHelper::regisFactory("scaleto", new ScaleToActionFactory);
        ActionHelper::regisFactory("fadeto", new FadeToActionFactory);
        ActionHelper::regisFactory("playsound", new PlaySoundActionFactory);
        ActionHelper::regisFactory("layout", new DoLayoutActionFactory);
        ActionHelper::regisFactory("delay", new DelayActionFactory);
        ActionHelper::regisFactory("animate", new AnimateActionFactory);
    }
}