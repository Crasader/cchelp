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
        
        hset<string> handled;
        
        auto handle = [&](string tag, const Parameter &p)
        {
            if (handled.find(tag) != handled.end())
                return;
            
            handled.insert(tag);
            
            // check if this tag is assign to a node
            Node *node = LayoutHelper::queryNode(root, tag);
            if (node)
            {
                doLayout(node, p);
                return;
            }
            
            // if this tag wasn't node
            for (char &c : tag) {c = tolower(c);}
            auto layoutIte = GroupLayout::Layouts.find(tag);
            if (layoutIte == GroupLayout::Layouts.end())
                return;
            
            // this tag is a layout
            Layout *layout = layoutIte->second;
            layout->doLayout(root, p);
        };
        
        if (par.isMember("order") && par["order"].isArray())
        {
            const auto &od = par["order"];
            for (uint i = 0; i < od.size(); ++i)
            {
                if (!od[i].isString())
                    continue;
                
                handle(od[i].asString(), par[od[i].asString()]);
            }
        }
        
        for (Json::ValueIterator it = par.begin(); it != par.end(); ++it)
        {
            handle(it.key().asString(), *it);
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