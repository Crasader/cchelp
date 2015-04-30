#pragma once
#include "cocos2d.h"
#include "Def.h"
#include <functional>

namespace ccHelp
{
	class Shortcut
	{
	public:
		static void registerTouch(cocos2d::Node *target,
			std::function<bool(cocos2d::Touch*, cocos2d::Event*)> touchBegan,
			std::function<void(cocos2d::Touch*, cocos2d::Event*)> touchMoved,
			std::function<void(cocos2d::Touch*, cocos2d::Event*)> touchEnded,
			std::function<void(cocos2d::Touch*, cocos2d::Event*)> touchCancelled,
			bool swallowTouch = true);

		static void registerTouchMove(cocos2d::Node *target,
			std::function<void(cocos2d::Touch*, cocos2d::Event*)> callBack,
			bool swallowTouch = true);

		static void registerTouchUp(cocos2d::Node *target,
			std::function<void(cocos2d::Touch*, cocos2d::Event*)> callBack,
			bool swallowTouch = true);

		static std::function<void(cocos2d::Touch*, cocos2d::Event*)>
			DO_NOTHING_TOUCH_HANDLER;
	};

	class ShortcutAction
	{
	public:
		static cocos2d::MoveTo* moveToBySpeed(cocos2d::Node *target,
			float speed, CREF(cocos2d::Vec2) dest);
		static cocos2d::MoveTo* moveToBySpeed(CREF(cocos2d::Vec2) start,
			float speed, CREF(cocos2d::Vec2) end);
	};
}