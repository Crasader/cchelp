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
    
    void GroupLayout::doLayout(cocos2d::Node *root, const Layout::Parameter &par) const
    {
        this->doLayout(root, par.getJson());
    }
    
    void GroupLayout::doLayout(cocos2d::Node *root, const Json::Value &par) const
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
            if (layoutIte != GroupLayout::Layouts.end())
            {
                // this tag is a layout
                Layout *layout = layoutIte->second;
                layout->doLayout(root, par[tag]);
                continue;
            }
            
            if (tag.length() > 0 && tag[0] == '+')
            {
                // this tag is new child
                auto childName = tag.substr(1, tag.length() - 1);
                layoutIte = GroupLayout::Layouts.find("addchild");
                if (layoutIte == GroupLayout::Layouts.end() || !layoutIte->second)
                    continue;
                
                auto *addChildLayout = layoutIte->second;
                Json::Value addChildPar = par[tag];
                addChildPar["name"] = childName;
                addChildLayout->doLayout(root, addChildPar);
                
                auto *newChild = root->getChildByName(childName);
                if (newChild)
                {
                    this->doLayout(newChild, addChildPar);
                }
            }
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