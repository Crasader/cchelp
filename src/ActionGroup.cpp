#include "ActionGroup.h"

USING_NS_CC;

namespace ccHelp
{
	ActionGroup::ActionGroup()
    : isFinished(false), isLocked(false)
	{
		this->retain();
	}

	void ActionGroup::lock()
	{
		isLocked = true;
		this->activeCallback();
	}

	FiniteTimeAction* ActionGroup::addAction(FiniteTimeAction *action)
    {
        CCASSERT(!isLocked, "The group already locked");
        
		if (!isLocked)
		{
			this->actions.pushBack(action);

			return Sequence::createWithTwoActions(action,
				CallFunc::create([action, this]
			{
				this->actions.eraseObject(action, false);
				this->activeCallback();
			}));
		}

		return nullptr;
	}

	void ActionGroup::activeCallback()
	{
		CCASSERT(!isFinished, "Group have been finished");
		CCASSERT(isLocked, "Group must be locked before use");

		if (actions.size() == 0)
		{
            Completion();
            
            isFinished = true;
            this->release();
		}
	}
}