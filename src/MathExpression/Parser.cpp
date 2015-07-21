//
//  Parser.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/10/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Parser.h"
#include <string>

using namespace std;

namespace ccHelp { namespace expr {
    Operator OPEN_PARENT = {"(", 0, false};
    Operator CLOSE_PARENT = {")", 0, false};
    
    bool isSpace(char c)
    {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }
    
    bool isSymbol(char c)
    {
        return ((c >= 'A' && c <= 'Z')) || ((c >= 'a' && c <= 'z')) || c == '_';
    }
    
    bool isDigit(char c)
    {
        return ((c >= '0') && (c <= '9')) || (c == '.');
    }
    
    bool isOperator(char c)
    {
        char s[] = {c, '\0'};
        Operator op = {s, 0, false};
        
        return ((op == Operator::ADD) ||
                (op == Operator::SUB) ||
                (op == Operator::MULT) ||
                (op == Operator::DIV) ||
                (op == Operator::POW) ||
                (op == OPEN_PARENT) ||
                (op == CLOSE_PARENT));

    }
    
    Operator& getOperator(const std::string &s)
    {
        if (s == Operator::ADD.OP)
        {
            return Operator::ADD;
        }
        else if (s == Operator::SUB.OP)
        {
            return Operator::SUB;
        }
        else if (s == Operator::MULT.OP)
        {
            return Operator::MULT;
        }
        else if (s == Operator::DIV.OP)
        {
            return Operator::DIV;
        }
        else if (s == Operator::POW.OP)
        {
            return Operator::POW;
        }
        else if (s == OPEN_PARENT.OP)
        {
            return OPEN_PARENT;
        }
        else if (s == CLOSE_PARENT.OP)
        {
            return CLOSE_PARENT;
        }
        
        throw invalid_argument("Not operator: " + s);
    }
    
    std::list<Token> postfixParse(const std::string &expr)
    {
        struct ParseIterator
        {
            ParseIterator()
            : index(0), token(NONE)
            {
                
            }
            
            unsigned int index;
            string current;
            TokenType token;
        };
        
        list<Token> infixToken;
        ParseIterator it;
        while (it.index < expr.length())
        {
            char c = expr[it.index];
            switch (it.token)
            {
                case NONE:
                {
                    if (isSpace(c))
                    {
                        // continue;
                    }
                    else if (isSymbol(c))
                    {
                        it.current += c;
                        it.token = SYMBOL;
                    }
                    else if (isDigit(c))
                    {
                        it.current += c;
                        it.token = NUMBER;
                    }
                    else if (isOperator(c))
                    {
                        // only accept 1 character operator
                        it.current += c;
                        infixToken.push_back(Token(OPERATOR, it.current));
                        it.current.clear();
                        it.token = NONE;
                    }
                }
                    break;
                case SYMBOL:
                {
                    if (isSpace(c))
                    {
                        infixToken.push_back(Token(SYMBOL, it.current));
                        it.current.clear();
                        it.token = NONE;
                    }
                    else if (isSymbol(c))
                    {
                        it.current += c;
                    }
                    else if (isDigit(c))
                    {
                        it.current += c;
                    }
                    else if (isOperator(c))
                    {
                        infixToken.push_back(Token(SYMBOL, it.current));
                        it.current.clear();
                        it.token = NONE;
                        --it.index;
                    }
                }
                    break;
                case NUMBER:
                {
                    if (isSpace(c))
                    {
                        infixToken.push_back(Token(NUMBER, it.current));
                        it.current.clear();
                        it.token = NONE;
                    }
                    else if (isSymbol(c))
                    {
                        throw invalid_argument(expr.substr(it.index, 1));
                    }
                    else if (isDigit(c))
                    {
                        it.current += c;
                    }
                    else if (isOperator(c))
                    {
                        infixToken.push_back(Token(NUMBER, it.current));
                        it.current.clear();
                        it.token = NONE;
                        --it.index;
                    }
                }
                    break;
                case OPERATOR:
                    break;
            }
            
            ++it.index;
        }
        if (it.token != NONE)
        {
            infixToken.push_back(Token(it.token, it.current));
        }
        
        list<Token> postfix, stOps;
        for (auto &token : infixToken)
        {
            if (token.type == OPERATOR)
            {
                if (token.value == OPEN_PARENT.OP)
                {
                    stOps.push_back(token);
                }
                else if (token.value == CLOSE_PARENT.OP)
                {
                    do
                    {
                        if (stOps.empty())
                            throw invalid_argument("invalid parentheness");
                        
                        Token op = stOps.back();
                        stOps.pop_back();
                        if (op.value == OPEN_PARENT.OP)
                        {
                            break;
                        }
                        postfix.push_back(op);
                    } while (true);
                }
                else
                {
                    auto &op = getOperator(token.value);
                    while (true) {
                        if (stOps.empty())
                            break;
                        
                        auto topToken = stOps.back();
                        auto &topOp = getOperator(topToken.value);
                        
                        if ((topOp.priority > op.priority) ||
                            (op.isRightAssocciative && topOp.priority == op.priority))
                        {
                            
                            stOps.pop_back();
                            postfix.push_back(topToken);
                        }
                        else
                        {
                            break;
                        }
                    }
                    stOps.push_back(token);
                }
            }
            else
            {
                postfix.push_back(token);
            }
        }
        
        while (!stOps.empty())
        {
            postfix.push_back(stOps.back());
            stOps.pop_back();
        }
        
        return postfix;
    }
} }