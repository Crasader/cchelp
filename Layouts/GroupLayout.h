//
//  GroupLayout.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#pragma once
#include "Layout.h"
#include "hmap.h"

namespace vin {
    class GroupLayout : public Layout
    {
    private:
        static hmap<string, Layout *> Layouts;
        static GroupLayout *inst;
        
    public:
        static void registerLayout(const string &k, Layout *layout);
        static GroupLayout* getInstance() {return inst;}
        
    public:
        virtual void doLayout(cocos2d::Node *node, const Parameter &par) const;
    };
}
