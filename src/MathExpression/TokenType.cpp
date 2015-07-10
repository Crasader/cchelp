//
//  Token.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/10/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "TokenType.h"

namespace ccHelp { namespace expr {
    Operator Operator::ADD = {"+", 1, false};
    Operator Operator::SUB = {"-", 1, false};
    Operator Operator::MULT = {"*", 2, false};
    Operator Operator::DIV = {"/", 2, false};
    Operator Operator::POW = {"^", 3, true};
} }