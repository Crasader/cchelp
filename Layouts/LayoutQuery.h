//
//  LayoutQuery.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "cocos2d.h"
#include <functional>

namespace ccHelp {
    typedef std::function<cocos2d::Node*(cocos2d::Node*)> LayoutQuery;
}
