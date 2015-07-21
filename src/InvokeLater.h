//
//  InvokeLater.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/21/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include "cocos2d.h"

namespace ccHelp {
    struct Job
    {
        std::function<void()> func;
        Job(std::function<void()> f)
        {
            func = f;
        }
    };
    
    class InvokeLater : public virtual obj
    {
    private:
        static InvokeLater* _instance;
        std::queue<Job> Jobs;
        
    public:
        static InvokeLater* getInstance();
        
    private:
        void doJobs();
        
    public:
        // this method is called in other thread, must be safer
        void invoke(std::function<void()> func);
    };
}