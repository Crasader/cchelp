//
//  Token.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/10/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "TokenType.h"
#include <string>

namespace ccHelp { namespace expr {
    struct Token
    {
        Token(TokenType _type, const std::string &val)
        : type(_type), value(val)
        {
        }
        
        const TokenType type;
        const std::string value;
    };
} }