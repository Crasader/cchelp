#pragma once
#include "Def.h"
#include "cocos2d.h"
#include <functional>
#include "Event.h"

using cocos2d::FiniteTimeAction;

namespace ccHelp
{
    
	class ActionGroup : public cocos2d::Ref
	{
    public:
        inline static ActionGroup* create()
		{
			ActionGroup *action = new ActionGroup();
            action->autorelease();
            return action;
		}

		FiniteTimeAction* addAction(FiniteTimeAction *action);
		
        void lock();
        ccHelp::Event<void()> Completion;
        
	protected:
	private:
		ActionGroup();
		void activeCallback();

		bool isLocked, isFinished;
		cocos2d::Vector<FiniteTimeAction *> actions;
	};
}