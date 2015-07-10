//
//  TokenType.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/10/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace ccHelp { namespace expr {
    enum TokenType
    {
        NONE,
        SYMBOL,
        NUMBER,
        OPERATOR,
    };
    
    struct Operator
    {
        const char *OP;
        const unsigned char priority;
        const bool isRightAssocciative;
        
        static Operator ADD;
        static Operator SUB;
        static Operator MULT;
        static Operator DIV;
        static Operator POW;
        
        inline bool operator==(const Operator &op) const
        {
            return strcmp(this->OP, op.OP) == 0;
        }
    };
} }