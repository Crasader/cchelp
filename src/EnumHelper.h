//
//  EnumHelper.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/5/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"

namespace ccHelp
{
    template<typename ENUM_TYPE>
    struct ENUM_ALL
    {
        static ENUM_TYPE VALUES[];
        static uint N;
    };
}