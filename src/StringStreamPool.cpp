//
//  StringStreamPool.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 11/6/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "StringStreamPool.h"

namespace ccHelp
{
    StringStreamPool GLOBAL_SSPOOL;
    
    StringStreamPool::StringStreamPool()
    : ObjectPool<ccHelp::SSPooledObject *>([this]{
        return new SSPooledObject(this);
    })
    {
        this->setObjectCleaner([](SSPooledObject *obj) {
            delete obj;
        });
        
        this->setOnReturn([](SSPooledObject *obj) {
            obj->clear();
        });
    }
    
    SSPooledObject::SSPooledObject(StringStreamPool *_pool)
    : pool(_pool)
    {
        
    }
    
    void SSPooledObject::clear()
    {
        static const std::string EMPTY;
        
        Stream.str(EMPTY);
    }
    
    std::string SSPooledObject::ret()
    {
        std::string s = Stream.str();
        pool->returnObj(this);
        return s;
    }
    
    SSPooledObject& sbuild()
    {
        auto *obj = GLOBAL_SSPOOL.getObj();
        return *obj;
    }
}