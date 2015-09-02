//
//  InvokeLater.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/21/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "InvokeLater.h"

namespace ccHelp
{
    InvokeLater* InvokeLater::_instance = nullptr;
    
    InvokeLater* InvokeLater::getInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new InvokeLater();
            cocos2d::Director::getInstance()->getScheduler()->schedule([=](float dt) {
                _instance->doJobs();
            }, _instance, 0, false, "InvokeLaterScheduleBackground");
        }
        
        return _instance;
    }
    
    void InvokeLater::doJobs()
    {
        while (!Jobs.empty())
        {
            auto job = Jobs.front();
            Jobs.pop();
            
            job.func();
        }
    }
    
    void InvokeLater::invoke(std::function<void()> func)
    {
        Jobs.push(Job(func));
    }
}