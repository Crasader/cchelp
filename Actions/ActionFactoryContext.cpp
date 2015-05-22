//
//  ActionFactoryContext.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#include "ActionFactoryContext.h"
#include "Utils.h"

namespace ccHelp {
    ActionContext::BaseHolder::~BaseHolder() {}
    
    ActionContext::ActionContext(const ActionContext &ctx)
    {
        for (auto it : ctx.mData)
        {
            mData[it.first] = it.second->clone();
        }
    }
    
    ActionContext& ActionContext::operator=(const ccHelp::ActionContext &ctx)
    {
        for (auto it : mData)
        {
            CC_SAFE_DELETE(it.second);
        }
        mData.clear();
        
        for (auto it : ctx.mData)
        {
            mData[it.first] = it.second->clone();
        }
        
        return *this;
    }
    
    ActionContext::ActionContext(ActionContext &&ctx)
    {
        for (auto it : ctx.mData)
        {
            mData[it.first] = it.second;
        }
        
        ctx.mData.clear();
    }
    
    ActionContext::~ActionContext()
    {
        for (auto it : mData)
        {
            CC_SAFE_DELETE(it.second);
        }
    }
    
    AFContext::AFContext(const ActionContext &ctx, const Json::Value &js)
    : ctx(ctx), js(js) {}
    
    AFContext::AFContext(const ActionContext &ctx, const vsson::VSSObject &vss)
    : ctx(ctx), mJs(Utils::jsonFromVsson(vss)), js(mJs) {}
}