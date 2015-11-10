#include "DialogLayer.h"
#include "Shortcut.h"
#include "Utils.h"

namespace ccHelp
{
	DialogLayer::DialogLayer(Node *parent,
		Node *dialog, CREF(Color4B) fillBackground)
	{
		Size contentSize = parent->getContentSize();

		background = LayerColor::create(fillBackground,
			contentSize.width, contentSize.height);
		background->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		background->setPosition(Vec2::ZERO);
		this->addChild(background, -1);

		this->dialog = dialog;
		this->addChild(this->dialog, 1);

		this->setContentSize(contentSize);
		Shortcut::registerTouchUp(this->background, [](Touch*, Event*){});
	}

	DialogLayer* DialogLayer::showDialog(Node *parent, Node *dialog,
		CREF(Color4B) fillBg, DialogAnimation anim,
		DialogAlign align, DIALOG_COMPLETION completion)
	{
		DialogLayer *dlgLayer = Utils::createnx(new DialogLayer(parent, dialog, fillBg));
		parent->addChild(dlgLayer, 0x1000);

		dialog->setPosition(alignInPoint(align, dlgLayer, dialog));

		FiniteTimeAction *showAction = makeShowAnim(anim, dlgLayer, dialog);
		if (showAction)
		{
			auto actionWithCallback = Sequence::createWithTwoActions(showAction,
				CallFunc::create([=]
			{
				completion(dlgLayer);
			}));

			dialog->runAction(actionWithCallback);
		}
		else
		{
			completion(dlgLayer);
		}

		return dlgLayer;
	}

	void DialogLayer::closeDialog(DialogLayer *dlgLayer, Node *dialog,
		DialogAnimation anim, DIALOG_COMPLETION completion)
	{
		CCASSERT(dialog->getParent() == dlgLayer, "Dialog layer must be parent of dialog");

		FiniteTimeAction *closeAcion = makeCloseAnim(anim, dlgLayer, dialog);
		if (closeAcion)
		{
			auto actionWithCompletion = Sequence::create(closeAcion,
				CallFunc::create([dlgLayer] {
                dlgLayer->removeFromParent();
            }),
				CallFunc::create([=]
			{
				completion(dlgLayer);
			}), nullptr);
			dialog->runAction(actionWithCompletion);
		}
		else
		{
			completion(dlgLayer);
		}
	}

	DialogLayer::DIALOG_COMPLETION DialogLayer::DO_NOTHING_COMPLETION =
		[](DialogLayer*) {};

	FiniteTimeAction* DialogLayer::makeShowAnim(DialogAnimation anim,
		Node *parent, Node *dlg)
	{
		static const float ANIM_DUR = 0.5f;

		if (anim == DialogAnimation::ZOOM_FADE)
		{
			auto targetOpac = dlg->getOpacity();
			auto targetScaleX = dlg->getScaleX();
			auto targetScaleY = dlg->getScaleY();

			dlg->setOpacity(0);
			dlg->setScale(targetScaleX / 2, targetScaleY / 2);

			auto zoomAction = EaseBackOut::create(
				ScaleTo::create(ANIM_DUR, targetScaleX, targetScaleY));
			auto fadeAction = FadeTo::create(ANIM_DUR, targetOpac);
			auto zoomFade = Spawn::createWithTwoActions(zoomAction, fadeAction);

			return zoomFade;
		}

		return nullptr;
	}

	FiniteTimeAction* DialogLayer::makeCloseAnim(DialogAnimation anim,
		Node *parent, Node *dlg)
	{
		static const float ANIM_DUR = 0.5f;

		if (anim == DialogAnimation::ZOOM_FADE)
		{
			auto zoomAction = EaseBackIn::create(
				ScaleTo::create(ANIM_DUR, 0, 0));
			auto fadeAction = FadeTo::create(ANIM_DUR, 0);
			auto zoomFade = Spawn::createWithTwoActions(zoomAction, fadeAction);

			return zoomFade;
		}

		return nullptr;
	}

	Vec2 DialogLayer::alignInPoint(DialogAlign align, Node *parent, Node *dlg)
	{
		if (align == CENTER)
		{
			return parent->getContentSize() / 2;
		}

		return dlg->getPosition();
	}
}