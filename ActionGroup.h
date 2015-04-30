#pragma once
#include "cocos2d.h"
#include <functional>
#include <hash_set>
#include "Def.h"

using cocos2d::FiniteTimeAction;

namespace ccHelp
{
	class ActionGroup : public cocos2d::Ref
	{
	public:
		inline static ActionGroup* create(std::function<void()> callBack)
		{
			ActionGroup *action = new ActionGroup(callBack);
			return CCH_NOT_INIT_CREATE(action);
		}

		FiniteTimeAction* addAction(FiniteTimeAction *action);
		void lock();
	protected:
	private:
		ActionGroup(std::function<void()> callBack);
		void activeCallback();

		std::function<void()> callBack;
		bool isLocked, isFinished;
		cocos2d::Vector<FiniteTimeAction *> actions;
	};
}