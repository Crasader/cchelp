//
//  Expression<T>.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/13/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once

namespace ccHelp { namespace expr {
    template <typename T>
    class FixedExpression : public Expression<T>
    {
    private:
        T val;
        
    public:
        FixedExpression<T>(T v)
        : val(v) {}
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return val;
        }
    };
    
    template <typename T>
    class VariableExpression : public Expression<T>
    {
    private:
        const std::string var;
        
    public:
        VariableExpression<T>(const std::string &v)
        : var(v) {}
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return ctx.getVariable(var);
        }
    };
    
    
    template <typename T>
    class AddExpression : public Expression<T>
    {
    private:
        const Expression<T> *e1, *e2;
        
    public:
        AddExpression<T>(const Expression<T> *_e1, const Expression<T> *_e2)
        : e1(_e1), e2(_e2) {}
        
        ~AddExpression<T>()
        {
            delete e1;
            delete e2;
        }
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return e1->eval(ctx) + e2->eval(ctx);
        }
    };
    
    template <typename T>
    class SubExpression : public Expression<T>
    {
    private:
        const Expression<T> *e1, *e2;
        
    public:
        SubExpression<T>(const Expression<T> *_e1, const Expression<T> *_e2)
        : e1(_e1), e2(_e2) {}
        
        ~SubExpression<T>()
        {
            delete e1;
            delete e2;
        }
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return e1->eval(ctx) - e2->eval(ctx);
        }
    };
    
    template <typename T>
    class MultExpression : public Expression<T>
    {
    private:
        const Expression<T> *e1, *e2;
        
    public:
        MultExpression<T>(const Expression<T> *_e1, const Expression<T> *_e2)
        : e1(_e1), e2(_e2) {}
        
        ~MultExpression<T>()
        {
            delete e1;
            delete e2;
        }
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return e1->eval(ctx) * e2->eval(ctx);
        }
    };
    
    template <typename T>
    class DivExpression : public Expression<T>
    {
    private:
        const Expression<T> *e1, *e2;
        
    public:
        DivExpression<T>(const Expression<T> *_e1, const Expression<T> *_e2)
        : e1(_e1), e2(_e2) {}
        
        ~DivExpression<T>()
        {
            delete e1;
            delete e2;
        }
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return e1->eval(ctx) / e2->eval(ctx);
        }
    };
    
    template <typename T>
    class PowExpression : public Expression<T>
    {
    private:
        const Expression<T> *e1, *e2;
        
    public:
        PowExpression<T>(const Expression<T> *_e1, const Expression<T> *_e2)
        : e1(_e1), e2(_e2) {}
        
        ~PowExpression<T>()
        {
            delete e1;
            delete e2;
        }
        
        virtual T eval(const ExpressionContext<T> &ctx) const override
        {
            return pow(e1->eval(ctx), e2->eval(ctx));
        }
    };
    
    template <typename T>
    class ExpressionFactory : public ccHelp::expr::ExprFactory<Expression<T>>
    {
    public:
        virtual Expression<T>* createNumber(const Token &t) const override
        {
            T val = ccHelp::lexical_cast<T>(t.value);
            return new FixedExpression<T>(val);
        }
        
        virtual Expression<T>* createSymbol(const Token &t) const override
        {
            return new VariableExpression<T>(t.value);
        }
        
        virtual uint getNumberReqArguments(const Token &t) const override
        {
            return 2;
        }
        
        virtual Expression<T>* createExpr(const Token &t, const std::vector<Expression<T> *> exprs) const override
        {
            if (t.value == Operator::ADD.OP)
            {
                return new AddExpression<T>(exprs[0], exprs[1]);
            }
            else if (t.value == Operator::SUB.OP)
            {
                return new SubExpression<T>(exprs[0], exprs[1]);
            }
            else if (t.value == Operator::MULT.OP)
            {
                return new MultExpression<T>(exprs[0], exprs[1]);
            }
            else if (t.value == Operator::DIV.OP)
            {
                return new DivExpression<T>(exprs[0], exprs[1]);
            }
            else if (t.value == Operator::POW.OP)
            {
                return new PowExpression<T>(exprs[0], exprs[1]);
            }
            
            return nullptr;
        }
    };
} }