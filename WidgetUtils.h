//
//  WidgetUtils.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#pragma once
#include "Utils.h"
#include "CocosGUI.h"

namespace ccHelp {
    class WidgetUtils
    {
    public:
        static void setLoadingBarPercent(cocos2d::ui::LoadingBar *bar, float percent, bool animated);
    };
}
