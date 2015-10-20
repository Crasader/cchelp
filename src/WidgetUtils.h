//
//  WidgetUtils.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/23/15.
//
//

#pragma once
#include "Utils.h"
#include "ui/CocosGUI.h"

namespace ccHelp {
    class WidgetUtils
    {
    public:
        static void setLoadingBarPercent(cocos2d::ui::LoadingBar *bar, float percent, bool animated);
        static void setLoadingBarPercentLimit(cocos2d::ui::LoadingBar *bar, float percent, float limit = 5.f);
        static Label* loadButtonTTFTitle(ui::Button *btn, const string &ttf, float fntSize = 12);
        static ui::Button* createTTFButton(const string &ttf, float fntSize = 12);
        static void clearRichText(ui::RichText *rt);
    };
}
