#include "Shortcut.h"

USING_NS_CC;

namespace ccHelp
{
	std::function<void(Touch*, Event*)> Shortcut::DO_NOTHING_TOUCH_HANDLER =
		[](Touch*, Event*){};

	void Shortcut::registerTouch(Node *target,
		std::function<bool(Touch*, Event*)> touchBegan,
		std::function<void(Touch*, Event*)> touchMoved,
		std::function<void(Touch*, Event*)> touchEnded,
		std::function<void(Touch*, Event*)> touchCancelled,
		bool swallowTouch /* = true */)
	{
		auto *listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(swallowTouch);

		listener->onTouchBegan = touchBegan;
		listener->onTouchEnded = touchEnded;
		listener->onTouchMoved = touchMoved;
		listener->onTouchCancelled = touchCancelled;

		Director::getInstance()->getEventDispatcher()
			->addEventListenerWithSceneGraphPriority(listener, target);
	}

	void Shortcut::registerTouchMove(Node *target,
		std::function<void(Touch*, Event*)> callBack,
		bool swallowTouch /* = true */)
	{
		Shortcut::registerTouch(target,
			[](Touch*, Event*)->bool{return true;},
			callBack,
			DO_NOTHING_TOUCH_HANDLER,
			DO_NOTHING_TOUCH_HANDLER,
			swallowTouch);
	}

	void Shortcut::registerTouchUp(Node *target,
		std::function<void(Touch*, Event*)> callBack,
		bool swallowTouch /* = true */)
	{
		Shortcut::registerTouch(target,
			[](Touch*, Event*)->bool{return true;},
			DO_NOTHING_TOUCH_HANDLER,
			callBack,
			DO_NOTHING_TOUCH_HANDLER,
			swallowTouch);
	}

	MoveTo* ShortcutAction::moveToBySpeed(cocos2d::Node *target,
		float speed, CREF(cocos2d::Vec2) dest)
	{
		return moveToBySpeed(target->getPosition(), speed, dest);
	}

	MoveTo* ShortcutAction::moveToBySpeed(CREF(Vec2) start,
		float speed, CREF(cocos2d::Vec2) end)
	{
		float dist = end.distance(start);
		float dur = dist / speed;

		return MoveTo::create(dur, end);
	}
}