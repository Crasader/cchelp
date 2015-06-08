//
//  OperationManager.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/6/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include <list>
#include <vector>
#include <queue>
#include <iostream>

namespace ccHelp {
    class /*interface*/ Operation
    {
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
        OperationSequence(const std::vector<Operation *> &ops);
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
        OperationGroup(const std::vector<Operation *> &ops);
        ~OperationGroup();
        virtual void run(CCH_CALLBACK completion) override;
    };
    
    enum OperationAddRule
    {
        RULE_NONE = 0,
        RULE_AT_FIRST = 1,
        RULE_AT_LAST = RULE_NONE
    };
    
    class OperationBuilder
    {
    public:
        enum BuildType
        {
            SEQUENCE,
            GROUP
        };
        
    private:
        static OperationBuilder INST;
        
        bool isBuilding;
        BuildType type;
        std::vector<Operation *> ops;
        
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
    private:
        std::deque<Operation *> ops;
        Operation *runningOp;
        
        void activeNextOperation();
        
    public:
        OperationQueue();
        ~OperationQueue();
        void pushBack(Operation *op);
        void pushFront(Operation *op);
        void push(Operation *op, OperationAddRule rule);
    };
    
    template<typename T>
    Operation* mkop(const T&);
    
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
        
        void newSequence(OperationAddRule rule = OperationAddRule::RULE_NONE);
        void newGroup(OperationAddRule rule = OperationAddRule::RULE_NONE);
        void closeCurrent();
        
        template<typename T>
        void addmk(const T& t, OperationAddRule rule = OperationAddRule::RULE_NONE)
        {
            this->add(mkop(t), rule);
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
    
    template<>
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
    
    template<>
    inline Operation* mkop(const std::function<void(CCH_CALLBACK)> &func1)
    {
        return new Func1Operation(func1);
    }
    
    extern OperationManager OP;
}