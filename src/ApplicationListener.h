//
//  ApplicationListener.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/30/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "Def.h"

namespace ccHelp
{
    class /*interface*/ ApplicationListener : public virtual obj
    {
    public:
        // This function will be called when the app is inactive. When comes a phone call,it's be invoked too
        virtual void applicationDidEnterBackground();
        
        // this function will be called when the app is active again
        virtual void applicationWillEnterForeground();
        
    public:
        static void dispatchEnterBackgroundEvent(cocos2d::Node *n);
        static void dispatchEnterForegroundEvent(cocos2d::Node *n);
    };
}