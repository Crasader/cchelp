//
//  Expression.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/13/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Parser.h"

namespace ccHelp { namespace expr {
    template <typename T>
    class ExpressionContext : public virtual ccHelp::obj
    {
    public:
        virtual T getVariable(const string &var) const = 0;
    };
    
    template <typename T>
    class Expression : public virtual ccHelp::obj
    {
    public:
        virtual T eval(const ExpressionContext<T> &ctx) const = 0;
    };
} }

#include "Expression.hpp"
