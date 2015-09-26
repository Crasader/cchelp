//
//  OperationManager.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/6/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "OperationManager.h"
#include "InvokeLater.h"

using namespace std;

namespace ccHelp {
    Operation::~Operation() {}
    
    OperationSequence::OperationSequence(const list<Operation *> &_ops)
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
    
    OperationGroup::OperationGroup(const list<Operation *> &_ops)
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
    
    OperationBuilder& OperationBuilder::begin(BuildType _type)
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
            ops.push_front(op);
            return *this;
        }
        else if (rule == RULE_AT_LAST)
        {
            ops.push_back(op);
            return *this;
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
                op = new OperationGroup(ops);
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
    
    OperationQueue::OperationJob::OperationJob(Operation *_op)
    : op(_op), ctx(nullptr)
    {
        
    }
    
    OperationQueue::OperationJob::~OperationJob()
    {
        if (op)
            delete op;
        
        if (ctx)
            delete ctx;
    }
    
    Operation* OperationQueue::OperationJob::getOperation() const
    {
        return op;
    }
    
    ccHelp::Context* OperationQueue::OperationJob::getContext()
    {
        if (!ctx)
        {
            ctx = new ccHelp::Context();
        }
        
        return ctx;
    }
    
    OperationQueue::OperationQueue()
    : runningJob(nullptr)
    {
        
    }
    
    OperationQueue::~OperationQueue()
    {
        for (OperationJob *job : ops)
        {
            delete job;
        }
        ops.clear();
    }
    
    void OperationQueue::pushBack(Operation *op)
    {
        this->ops.push_back(new OperationJob(op));
        this->activeNextOperation();
    }
    
    void OperationQueue::pushFront(Operation *op)
    {
        this->ops.push_front(new OperationJob(op));
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
        if (runningJob || this->ops.empty())
            return;
        
        OperationJob *topJob = this->ops.front();
        this->ops.pop_front();
        
        runningJob = topJob;
        topJob->getOperation()->run([=] {
            runningJob = nullptr;
            delete topJob;
            
            this->activeNextOperation();
        });
    }
    
    bool OperationQueue::isOperating() const
    {
        return runningJob != nullptr;
    }
    
    OperationQueue::OperationJob* OperationQueue::getCurrentJob() const
    {
        return runningJob;
    }
    
    void OperationQueue::await(ccHelp::OperationQueue& opQueue, OperationAddRule rule)
    {
        struct WaitOperation : public Operation
        {
            CCH_FUNCTION completion;
            bool isFinished;
            
            WaitOperation() : completion(nullptr), isFinished(false) {}
            virtual void run(CCH_CALLBACK _compl) override
            {
                completion = _compl;
                this->checkCompletion();
            }
            
            void notify()
            {
                isFinished = true;
                this->checkCompletion();
            }
            
            void checkCompletion()
            {
                if (isFinished && completion)
                {
                    completion();
                }
            }
        };
        
        struct NotifyOperation : public Operation
        {
            WaitOperation *waiter;
            
            NotifyOperation(WaitOperation *_waiter) : waiter(_waiter) {};
            
            virtual void run(CCH_CALLBACK completion) override
            {
                waiter->notify();
                completion();
            }
        };
        
        WaitOperation *waitOp = new WaitOperation();
        NotifyOperation *notifyOp = new NotifyOperation(waitOp);
        
        this->push(waitOp, rule);
        opQueue.pushBack(notifyOp);
    }
    
    void OperationQueue::awaitFront(OperationQueue &queue)
    {
        this->await(queue, RULE_AT_FIRST);
    }
    
    void OperationQueue::awaitBack(OperationQueue &queue)
    {
        this->await(queue, RULE_AT_LAST);
    }
    
    class DelayOperation : public Operation
    {
    public:
        float delay;
        
        DelayOperation(float time) : delay(time) {}
        
        virtual void run(CCH_CALLBACK _compl) override
        {
            InvokeLater::getInstance()->invoke([=]{
                _compl();
            }, delay);
        }
    };
    
    void OperationQueue::delay(float t, OperationAddRule rule)
    {
        this->push(new DelayOperation(t), rule);
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
    }
    
    OperationManager::~OperationManager()
    {
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
            mQueue.push(op, rule);
        }
    }
    
//    void OperationManager::addInSubSeq(Operation *op, OperationAddRule rule)
//    {
//        function<void(CCH_CALLBACK)> func = [=](CCH_CALLBACK completion) {
//            this->newSequence(rule);
//            op->run(completion);
//            this->closeCurrent();
//        };
//        this->addmk(func);
//    }
//    
//    void OperationManager::addInSubGr(Operation *op, OperationAddRule rule)
//    {
//        function<void(CCH_CALLBACK)> func = [=](CCH_CALLBACK completion) {
//            this->newGroup(rule);
//            op->run(completion);
//            this->closeCurrent();
//        };
//        this->addmk(func);
//    }
    
    void OperationManager::newSequence(OperationAddRule rule)
    {
        if (currentBuilding.builder)
        {
            stackedBuildings.push(currentBuilding);
        }
        
        currentBuilding.builder = new OperationBuilder();
        currentBuilding.rule = rule;
        currentBuilding.builder->begin(SEQUENCE);
    }
    
    void OperationManager::newGroup(OperationAddRule rule)
    {
        if (currentBuilding.builder)
        {
            stackedBuildings.push(currentBuilding);
        }
        
        currentBuilding.builder = new OperationBuilder();
        currentBuilding.rule = rule;
        currentBuilding.builder->begin(GROUP);
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
            mQueue.push(op, currentBuilding.rule);
        }
    }
    
    ccHelp::Context& OperationManager::currentContext()
    {
        return *(mQueue.getCurrentJob()->getContext());
    }
    
    bool OperationManager::isOperating() const
    {
        return mQueue.isOperating();
    }
    
    void OperationManager::delay(float t, OperationAddRule rule)
    {
        this->add(new DelayOperation(t), rule);
    }
    
    void OperationManager::await(ccHelp::OperationManager &op, OperationAddRule rule)
    {
        return mQueue.await(op.mQueue, rule);
    }
    
    Operation* mkop(cocos2d::Node *target, cocos2d::FiniteTimeAction *act)
    {
        class ActionOperation : public Operation
        {
        public:
            cocos2d::FiniteTimeAction *act;
            cocos2d::Node *target;
            
        public:
            virtual void run(CCH_CALLBACK completion) override
            {
                cocos2d::CallFunc *cfCompl = cocos2d::CallFunc::create(completion);
                cocos2d::Sequence *actWithCompl = cocos2d::Sequence::createWithTwoActions(act, cfCompl);
                target->runAction(actWithCompl);
                act->release();
            }
        };
        
        act->retain();
        auto *op = new ActionOperation;
        op->act = act;
        op->target = target;
        
        return op;
    }
    
    OperationManager OP;
}