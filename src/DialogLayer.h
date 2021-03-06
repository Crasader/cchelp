#pragma once
#include "cocos2d.h"
#include "Def.h"

USING_NS_CC;

namespace ccHelp
{
	enum DialogAnimation
	{
		NONE = 0,
		ZOOM_FADE = 1
	};

    typedef std::function<Vec2(Node *, Node *)> DialogAlign;
    extern DialogAlign NO_ALIGN;
    extern DialogAlign CENTER;
    extern DialogAlign BOTTOM_CENTER;

	class DialogLayer : public Node
	{
	public:
		DialogLayer(Node *parent,
			Node *dialog, CREF(Color4B) fillBackground = Color4B());

	private:
		LayerColor *background;
		Node *dialog;

	public:
		typedef std::function<void(DialogLayer *)> DIALOG_COMPLETION;
		static DIALOG_COMPLETION DO_NOTHING_COMPLETION;

		static DialogLayer* showDialog(Node *parent, Node *dialog,
			CREF(Color4B) fillBg = Color4B(),
			DialogAnimation anim = DialogAnimation::NONE,
			DialogAlign align = NO_ALIGN,
			DIALOG_COMPLETION completion = DO_NOTHING_COMPLETION);

		static void closeDialog(DialogLayer *dlgLayer, Node *dialog,
			DialogAnimation anim = DialogAnimation::NONE, DIALOG_COMPLETION completion = DO_NOTHING_COMPLETION);

	private:
		static FiniteTimeAction* makeShowAnim(DialogAnimation anim, Node *parent, Node *dlg);	private:
		static FiniteTimeAction* makeCloseAnim(DialogAnimation anim, Node *parent, Node *dlg);
	};
}