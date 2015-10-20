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
                float d = 30 * dt;
                
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
    
    void WidgetUtils::setLoadingBarPercentLimit(cocos2d::ui::LoadingBar *bar, float percent, float limit)
    {
        assert(limit > 0);
        float delta = percent - bar->getPercent();
        if (delta != 0.f)
        {
            delta = (delta / fabsf(delta)) * fmin(fabsf(delta), limit);
            bar->setPercent(bar->getPercent() + delta);
        }
    }
    
    Label* WidgetUtils::loadButtonTTFTitle(ui::Button *btn, const string &ttf, float fntSize)
    {
        struct _Button : public ui::Button
        {
            void setTitleRenderer(Label *lbl)
            {
                if (!lbl)
                    return;
                
                if (_titleRenderer)
                    _titleRenderer->removeFromParent();
                
                if (lbl->getParent() != this)
                {
                    lbl->removeFromParent();
                    this->addProtectedChild(lbl);
                }
                
                this->_titleRenderer = lbl;
            }
        };
        
        auto *ttfTitle = Label::createWithTTF(btn->getTitleText(), ttf, fntSize);
        ((_Button *) btn)->setTitleRenderer(ttfTitle);
        
        return ttfTitle;
    }
    
    ui::Button* WidgetUtils::createTTFButton(const string &ttf, float fntSize)
    {
        ui::Button *btn = ui::Button::create();
        loadButtonTTFTitle(btn, ttf, fntSize);
        
        return btn;
    }
    
    void WidgetUtils::clearRichText(ui::RichText *rt)
    {
        struct _RT : public ui::RichText
        {
        public:
            void clearElems()
            {
                _richElements.clear();
                _formatTextDirty = true;
            }
        };
        
        static_cast<_RT *>(rt)->clearElems();
    }
}