//
//  ApplicationListener.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/30/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "ApplicationListener.h"

namespace ccHelp
{
    void ApplicationListener::applicationDidEnterBackground()
    {
        
    }
    
    void ApplicationListener::applicationWillEnterForeground()
    {
        
    }
    
    void ApplicationListener::dispatchEnterBackgroundEvent(cocos2d::Node *n)
    {
        if (!n)
            return;
        
        auto *al = dynamic_cast<ApplicationListener *>(n);
        if (al)
        {
            al->applicationDidEnterBackground();
        }
        
        for (auto *child : n->getChildren())
        {
            ApplicationListener::dispatchEnterBackgroundEvent(child);
        }
    }
    
    void ApplicationListener::dispatchEnterForegroundEvent(cocos2d::Node *n)
    {
        if (!n)
            return;
        
        auto *al = dynamic_cast<ApplicationListener *>(n);
        if (al)
        {
            al->applicationWillEnterForeground();
        }
        
        for (auto *child : n->getChildren())
        {
            ApplicationListener::dispatchEnterForegroundEvent(child);
        }
    }
}