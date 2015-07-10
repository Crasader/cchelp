//
//  Parser.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/10/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Token.h"
#include <list>

namespace ccHelp { namespace expr {    
    extern std::list<Token> postfixParse(const std::string &expr);
} }