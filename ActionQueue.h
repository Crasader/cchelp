#pragma once
#include "cocos2d.h"
#include <queue>
#include <functional>
#include "Def.h"

namespace ccHelp
{
#define DELEGATE std::function<void(const ActionQueue &queue)>
	class ActionQueue
	{
	public:
		ActionQueue(cocos2d::Node *target);
		void push(cocos2d::FiniteTimeAction *action);

	private:
		cocos2d::Node *target;
		cocos2d::FiniteTimeAction *currentAction;
		std::queue<cocos2d::FiniteTimeAction *> actionQueue;
		DELEGATE actionChanged;

	public:
		PROPERTY_GET(cocos2d::Node*, Target, target);
		PROPERTY_GET(const cocos2d::FiniteTimeAction*, currentAction, currentAction);
		PROPERTY_SET(DELEGATE, OnActionChanged, actionChanged);
	private:
		void pollAction();
	};

#undef DELEGATE
}