//
//  WidgetUtils.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#include "WidgetUtils.h"

namespace ccHelp {
    void WidgetUtils::setLoadingBarPercent(cocos2d::ui::LoadingBar *bar, float targetPercent, bool animated)
    {
        static const string SCHEDULE_KEY = "LoadingBarAnimatedUpdate";
        
        targetPercent = MAX(0, MIN(100, targetPercent));
        bar->unschedule(SCHEDULE_KEY);
        
        if (targetPercent == bar->getPercent())
            return;
        
        if (!animated)
        {
            bar->setPercent(targetPercent);
        }
        else
        {
            bar->schedule([=](float dt) {
                const float currentDistance = targetPercent - bar->getPercent();
                float d = 100 * dt;
                
                if (d >= fabsf(currentDistance))
                {
                    bar->setPercent(targetPercent);
                    bar->unschedule(SCHEDULE_KEY);
                    return;
                }
                
                d *= currentDistance / fabsf(currentDistance);
                bar->setPercent(bar->getPercent() + d);
            }, SCHEDULE_KEY);
        }
    }
}