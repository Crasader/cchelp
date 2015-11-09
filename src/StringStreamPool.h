//
//  StringStreamPool.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 11/6/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "ObjectPool.h"

namespace ccHelp
{
    class StringStreamPool;
    
    enum SSTOKEN : char
    {
        ret
    };
    
    class SSPooledObject : public ccHelp::obj
    {
    private:
        StringStreamPool *pool;
        std::stringstream Stream;
        
    public:
        
    public:
        SSPooledObject(StringStreamPool *_pool);
        
        void clear();
        
        inline std::string operator%(SSTOKEN tok)
        {
            return this->ret();
        }
        
        template <typename T>
        SSPooledObject& operator%(const T& t)
        {
            this->Stream<<t;
            return *this;
        }
        
        inline operator std::string()
        {
            return ret();
        }
        
        inline operator const char*()
        {
            return ret().c_str();
        }
        
        std::string ret();
    };
    
    class StringStreamPool : public ObjectPool<SSPooledObject *>
    {
    public:
        StringStreamPool();
    };
    
    SSPooledObject& sbuild();
}