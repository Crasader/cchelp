#pragma once
#include "jsoncpp/serializor.hpp"
#include "jsoncpp/object_str.hpp"
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
        JSONCPP_STR_DEFINE_NEW_TYPE(cocos2d::Size);
        
        JSONCPP_DEFINE_NEW_TYPE(cocos2d::Vec2, v, "x", v.x, "y", v.y);
        JSONCPP_STR_DEFINE_NEW_TYPE(cocos2d::Vec2);
        
        JSONCPP_DEFINE_NEW_TYPE(cocos2d::Rect, r, "origin", r.origin, "size", r.size);
        JSONCPP_STR_DEFINE_NEW_TYPE(cocos2d::Rect);
	}
}