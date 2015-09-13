//
//  OperationManager.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/6/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include "Context/Context.h"
#include <list>
#include <queue>
#include <iostream>

namespace ccHelp {
    class /*interface*/ Operation
    {
    private:
        
    public:
        virtual ~Operation();
        virtual void run(CCH_CALLBACK completion) = 0;
        
        // may has
        // pause, resume, stop, start,....
    };
    
    class OperationSequence : public Operation
    {
    private:
        std::queue<Operation *> ops;
        CCH_FUNCTION completion;
        
        void activeNextOperation();
        
    public:
        OperationSequence(const std::list<Operation *> &ops);
        ~OperationSequence();
        virtual void run(CCH_CALLBACK completion) override;
    };
    
    class OperationGroup : public Operation
    {
    private:
        std::list<Operation *> ops;
        uint nRemainOperations;
        CCH_FUNCTION completion;
        
        void checkCompletion();
        
    public:
        OperationGroup(const std::list<Operation *> &ops);
        ~OperationGroup();
        virtual void run(CCH_CALLBACK completion) override;
    };
    
    enum OperationAddRule
    {
        RULE_NONE,
        RULE_AT_FIRST = 1,
        RULE_AT_LAST = RULE_NONE
    };
    
    enum BuildType
    {
        SEQUENCE,
        GROUP
    };
    
    class OperationBuilder
    {
    private:
        static OperationBuilder INST;
        
        bool isBuilding;
        BuildType type;
        std::list<Operation *> ops;
        
    public:
        OperationBuilder();
        ~OperationBuilder();
        OperationBuilder& begin(BuildType type);
        OperationBuilder& add(Operation *op, OperationAddRule rule);
        Operation* build();
        
        static OperationBuilder& BUILDER();
    };
    
    class OperationQueue
    {
    public:
        struct OperationJob
        {
        private:
            Operation *op;
            ccHelp::Context *ctx;
            
        public:
            OperationJob(Operation *op);
            ~OperationJob();
            
            Operation* getOperation() const;
            ccHelp::Context* getContext();
        };
        
    private:
        std::deque<OperationJob *> ops;
        OperationJob *runningJob;
        
        void activeNextOperation();
        
    public:
        OperationQueue();
        ~OperationQueue();
        void pushBack(Operation *op);
        void pushFront(Operation *op);
        void push(Operation *op, OperationAddRule rule);
        OperationJob* getCurrentJob() const;
        bool isOperating() const;
        
        void await(OperationQueue &opQueue);
    };
    
//    template<typename T>
//    Operation* mkop(const T&);
    
    class OperationManager : public OperationQueue
    {
    private:
        struct Building
        {
            Building();
            void releaseAll();
            
            OperationBuilder *builder;
            OperationAddRule rule;
        };
        
    private:
        OperationQueue *opQueue;
        
        std::stack<OperationManager::Building> stackedBuildings;
        OperationManager::Building currentBuilding;
        
    public:
        OperationManager();
        ~OperationManager();
        void add(Operation *op, OperationAddRule rule = OperationAddRule::RULE_NONE);
        void addInSubSeq(Operation *op, OperationAddRule rule = OperationAddRule::RULE_NONE);
        void addInSubGr(Operation *op, OperationAddRule rule = OperationAddRule::RULE_NONE);
        
        void newSequence(OperationAddRule rule = OperationAddRule::RULE_NONE);
        void newGroup(OperationAddRule rule = OperationAddRule::RULE_NONE);
        void closeCurrent();
        
        bool isOperating() const;
        
        ccHelp::Context& currentContext();
        
        template<typename T>
        void addmk(const T& t, OperationAddRule rule = OperationAddRule::RULE_NONE);
        
        template<typename T>
        void addmkInSubSeq(const T& t, OperationAddRule rule = OperationAddRule::RULE_AT_FIRST)
        {
            this->addInSubSeq(mkop(t), rule);
        }
        
        template<typename T>
        void addmkInSubGr(const T& t, OperationAddRule rule = OperationAddRule::RULE_AT_FIRST)
        {
            this->addInSubGr(mkop(t), rule);
        }
    };
    
    class Func0Operation : public Operation
    {
    private:
        std::function<void(void)> func0;
        
    public:
        Func0Operation(const std::function<void(void)> &func)
        : func0(func) {}
        inline virtual void run(CCH_CALLBACK completion) override
        {
            func0();
            completion();
        }
    };
    
//    template<>
    inline Operation* mkop(const std::function<void(void)> &func0)
    {
        return new Func0Operation(func0);
    }
    
    class Func1Operation : public Operation
    {
    private:
        std::function<void(CCH_CALLBACK)> func1;
        
    public:
        Func1Operation(const std::function<void(CCH_CALLBACK)> &func)
        : func1(func) {}
        
        inline virtual void run(CCH_CALLBACK completion) override
        {
            func1(completion);
        }
    };
    
//    template<>
    inline Operation* mkop(const std::function<void(CCH_CALLBACK)> &func1)
    {
        return new Func1Operation(func1);
    }
    
    Operation* mkop(cocos2d::Node *target, cocos2d::FiniteTimeAction *act);
    
    template<typename T>
    void OperationManager::addmk(const T& t, OperationAddRule rule)
    {
        this->add(mkop(t), rule);
    }
    
//    extern OperationManager OP;
    
#define MKOP CC_CALLBACK_0
}