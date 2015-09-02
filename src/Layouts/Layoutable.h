//
//  Layoutable.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/17/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"

namespace ccHelp {
    class Layoutable : virtual public obj
    {
    public:
        virtual void onLayout() = 0;
    };
}