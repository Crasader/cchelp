//
//  AddChildLayouts.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 10/12/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#ifndef ccHelp_ios_mac_AddChildLayouts_h
#define ccHelp_ios_mac_AddChildLayouts_h
#pragma once
#include "Def.h"
#include "Layout.h"

namespace ccHelp {
    class AddChildLayout : public Layout
    {
    public:
        typedef std::function<cocos2d::Node*(const Layout::Parameter &p)> Factory;
        
    public:
        static hmap<string, Factory> FACTORIES;
        
    public:
        virtual void doLayout(cocos2d::Node *root, const Layout::Parameter &p) const override;
        
    public:
        STATIC_CONSTRUCTOR_DECLARE(AddChildLayout);
    };
}

#endif
