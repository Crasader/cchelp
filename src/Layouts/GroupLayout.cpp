//
//  GroupLayout.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#include "GroupLayout.h"
#include "LayoutHelper.h"
#include "hash_container/hset.h"
#include "Utils.h"
#include <stack>

USING_NS_CC;
using namespace std;

namespace ccHelp {
    hmap<string, Layout *> GroupLayout::Layouts;
    GroupLayout* GroupLayout::inst = new GroupLayout;
    
    void GroupLayout::doLayout(cocos2d::Node *root, const Parameter &par) const
    {
        if (!par.isObject())
        {
#if COCOS2D_DEBUG
            CCASSERT(false, "Group Layout require object param");
#endif
            return;
        }
        
        auto tags = par.getOrderedMemberNames();
        for (auto &tag : tags)
        {
            // check if this tag is assign to a node
            Node *node = LayoutHelper::queryNode(root, tag);
            if (node)
            {
                doLayout(node, par[tag]);
                continue;
            }
            
            // if this tag wasn't node, it may be a layout method
            auto layoutTag = Utils::tolower(tag);
            auto layoutIte = GroupLayout::Layouts.find(layoutTag);
            if (layoutIte == GroupLayout::Layouts.end())
                continue;
            
            // this tag is a layout
            Layout *layout = layoutIte->second;
            layout->doLayout(root, par[tag]);
        }
    }
    
    void GroupLayout::registerLayout(const string &k, ccHelp::Layout *layout)
    {
        string tag = k;
        for (char &c : tag)
        {
            c = tolower(c);
        }
        
        CCASSERT(Layouts.find(tag) == Layouts.end(), "Layout already existed");
        Layouts[tag] = layout;
    }
}