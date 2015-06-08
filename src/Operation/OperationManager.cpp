//
//  OperationManager.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/6/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "OperationManager.h"

using namespace std;

namespace ccHelp2 {
    Operation::~Operation() {}
    
    OperationSequence::OperationSequence(const vector<Operation *> &_ops)
    {
        for (Operation *op : _ops)
        {
            ops.push(op);
        }
    }
    
    OperationSequence::~OperationSequence()
    {
        while (!ops.empty())
        {
            delete ops.front();
            ops.pop();
        }
    }
    
    void OperationSequence::run(CCH_CALLBACK _completion)
    {
        this->completion = _completion;
        this->activeNextOperation();
    }
    
    void OperationSequence::activeNextOperation()
    {
        if (ops.empty())
        {
            this->completion();
            return;
        }
        
        Operation *op = this->ops.front();
        this->ops.pop();
        op->run([this, op] {
            delete op;
            this->activeNextOperation();
        });
    }
    
    OperationGroup::OperationGroup(const vector<Operation *> &_ops)
    : nRemainOperations(0)
    {
        ops.assign(_ops.begin(), _ops.end());
        nRemainOperations = (uint) ops.size();
    }
    
    OperationGroup::~OperationGroup()
    {
        for (Operation *op : ops)
        {
            delete op;
        }
        ops.clear();
    }
    
    void OperationGroup::run(CCH_CALLBACK _completion)
    {
        this->completion = _completion;
        
        for (Operation *op : this->ops)
        {
            op->run([=] {
                delete op;
                this->checkCompletion();
            });
        }
        this->ops.clear();
    }
    
    void OperationGroup::checkCompletion()
    {
        assert(nRemainOperations > 0);
        
        --nRemainOperations;
        if (nRemainOperations == 0)
        {
            this->completion();
            return;
        }
    }
    
    OperationBuilder::OperationBuilder()
    : isBuilding(false)
    {
        
    }
    
    OperationBuilder& OperationBuilder::begin(OperationBuilder::BuildType _type)
    {
        assert(!isBuilding);
        assert(ops.size() == 0);
        
        this->type = _type;
        isBuilding = true;
        
        return *this;
    }
    
    OperationBuilder& OperationBuilder::add(Operation *op, OperationAddRule rule)
    {
        assert(isBuilding);
        
        if (rule == RULE_AT_FIRST)
        {
            ops.insert(ops.begin(), op);
        }
        else if (rule == RULE_AT_LAST)
        {
            ops.push_back(op);
        }
        
        assert(false);
    }
    
    Operation* OperationBuilder::build()
    {
        assert(isBuilding);
        
        Operation *op = nullptr;
        switch (type) {
            case SEQUENCE:
                op = new OperationSequence(ops);
                break;
            case GROUP:
                op = new OperationSequence(ops);
                break;
        }
        
        ops.clear();
        isBuilding = false;
        
        return op;
    }
    
    OperationBuilder::~OperationBuilder()
    {
        for (Operation *op : ops)
        {
            delete op;
        }
        ops.clear();
    }
    
    OperationBuilder& OperationBuilder::BUILDER()
    {
        return INST;
    }
    
    OperationBuilder OperationBuilder::INST;
    
    OperationQueue::OperationQueue()
    : runningOp(nullptr)
    {
        
    }
    
    OperationQueue::~OperationQueue()
    {
        for (Operation *op : ops)
        {
            delete op;
        }
        ops.clear();
    }
    
    void OperationQueue::pushBack(Operation *op)
    {
        this->ops.push_back(op);
        this->activeNextOperation();
    }
    
    void OperationQueue::pushFront(Operation *op)
    {
        this->ops.push_front(op);
    }
    
    void OperationQueue::push(Operation *op, OperationAddRule rule)
    {
        switch (rule) {
            case OperationAddRule::RULE_AT_FIRST :
                pushFront(op);
                break;
                
            case OperationAddRule::RULE_AT_LAST:
                pushBack(op);
                break;
        }
    }
    
    void OperationQueue::activeNextOperation()
    {
        if (runningOp || this->ops.empty())
            return;
        
        Operation *topOp = this->ops.front();
        this->ops.front();
        
        runningOp = topOp;
        topOp->run([=] {
            runningOp = nullptr;
            delete topOp;
            
            this->activeNextOperation();
        });
    }
    
    OperationManager::Building::Building()
    : builder(nullptr), rule(RULE_AT_FIRST)
    {
        
    }
    
    void OperationManager::Building::releaseAll()
    {
        if (builder)
        {
            delete builder;
            builder = nullptr;
        }
        
        rule = RULE_NONE;
    }
    
    OperationManager::OperationManager()
    {
        opQueue = new OperationQueue();
    }
    
    OperationManager::~OperationManager()
    {
        delete opQueue;
        currentBuilding.releaseAll();
        while (!stackedBuildings.empty())
        {
            stackedBuildings.top().releaseAll();
            stackedBuildings.pop();
        }
    }
    
    void OperationManager::add(Operation *op, OperationAddRule rule)
    {
        if (currentBuilding.builder)
        {
            currentBuilding.builder->add(op, rule);
        }
        else
        {
            opQueue->push(op, rule);
        }
    }
    
    void OperationManager::newSequence(OperationAddRule rule)
    {
        if (currentBuilding.builder)
        {
            stackedBuildings.push(currentBuilding);
        }
        
        currentBuilding.builder = new OperationBuilder();
        currentBuilding.rule = rule;
        currentBuilding.builder->begin(OperationBuilder::SEQUENCE);
    }
    
    void OperationManager::newGroup(OperationAddRule rule)
    {
        if (currentBuilding.builder)
        {
            stackedBuildings.push(currentBuilding);
        }
        
        currentBuilding.builder = new OperationBuilder();
        currentBuilding.rule = rule;
        currentBuilding.builder->begin(OperationBuilder::SEQUENCE);
    }
    
    void OperationManager::closeCurrent()
    {
        assert(currentBuilding.builder);
        
        Operation *op = currentBuilding.builder->build();
        OperationAddRule rule = currentBuilding.rule;
        
        currentBuilding.releaseAll();
        
        if (!stackedBuildings.empty())
        {
            currentBuilding = stackedBuildings.top();
            stackedBuildings.pop();
            
            currentBuilding.builder->add(op, rule);
        }
        else
        {
            this->opQueue->push(op, currentBuilding.rule);
        }
    }
    
    OperationManager OP;
}