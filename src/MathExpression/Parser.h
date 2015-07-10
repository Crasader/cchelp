//
//  Parser.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/10/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include "Token.h"
#include <list>
#include <stdexcept>

namespace ccHelp { namespace expr {    
    extern std::list<Token> postfixParse(const std::string &expr);
    
    template <typename E>
    struct ExprFactory
    {
        virtual E* createNumber(const Token &t) const = 0;
        virtual E* createSymbol(const Token &t) const = 0;
        virtual uint getNumberReqArguments(const Token &t) const = 0;
        virtual E* createExpr(const Token &t, const std::vector<E *> exprs) const = 0;
    };
    
    template <typename E>
    E* parseExpression(const std::string &expr, const ExprFactory<E> &ef);
} }

template <typename E>
E* ccHelp::expr::parseExpression(const std::string &sExpr, const ccHelp::expr::ExprFactory<E> &ef)
{
    auto postfix = postfixParse(sExpr);
    
    std::stack<E *> buildingExprs;
    std::vector<E *> args;
    for (auto &token : postfix)
    {
        if (token.type == NUMBER)
        {
            buildingExprs.push(ef.createNumber(token));
        }
        else if (token.type == SYMBOL)
        {
            buildingExprs.push(ef.createSymbol(token));
        }
        else
        {
            uint nReqArgs = ef.getNumberReqArguments(token);
            if (buildingExprs.size() < nReqArgs)
                throw std::invalid_argument("Cannot build argument for token" + token.value);
            
            args.reserve(nReqArgs);
            for (auto i = 0; i < nReqArgs; ++i)
            {
                args.push_back(buildingExprs.top());
                buildingExprs.pop();
            }
            std::reverse(args.begin(), args.end());
            
            E* expr = ef.createExpr(token, args);
            if (!expr)
                throw std::invalid_argument("Cannot create expression for token" + token.value);
            
            buildingExprs.push(expr);
        }
    }
    
    if (buildingExprs.size() != 1)
        throw std::invalid_argument("More than 1 expression in: " + sExpr);
    
    return buildingExprs.top();
}