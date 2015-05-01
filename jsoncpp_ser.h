#pragma once
#include "jsoncpp/jsonserialization.h"
#include "Array2D.h"
#include "cocos2d.h"

USING_CC_HELP;

namespace Json
{
	namespace type
	{
		JSONCPP_DEFINE_NEW_TYPE(ccHelp::Index2D, idx, "row",
			idx.row, "col", idx.col);
		JSONCPP_STR_DEFINE_NEW_TYPE(ccHelp::Index2D);
		JSONCPP_DEFINE_NEW_TYPE(cocos2d::Size, sz, "width",
			sz.width, "height", sz.height);
	}
}