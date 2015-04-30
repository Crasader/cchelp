#include "ActionQueue.h"

USING_NS_CC;

namespace ccHelp
{
	ActionQueue::ActionQueue(Node *target) :
		target(target),
		currentAction(NULL)
	{

	}

	void ActionQueue::push(FiniteTimeAction *action)
	{
		action->retain();
		actionQueue.push(action);

		this->pollAction();
	}

	void ActionQueue::pollAction()
	{
		if (!this->currentAction && !this->actionQueue.empty())
		{
			FiniteTimeAction *action = actionQueue.front();
			actionQueue.pop();

			auto actionWithNextPoll = Sequence::createWithTwoActions(action,
				CallFunc::create([this]()
			{
				CC_SAFE_RELEASE_NULL(this->currentAction);
				this->pollAction();
			}));

			this->currentAction = action;
			if (this->actionChanged)
			{
				this->actionChanged(*this);
			}
			target->runAction(actionWithNextPoll);
		}
	}
}