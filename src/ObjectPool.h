//
//  ObjectPool.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/11/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include "hash_container/hset.h"

namespace ccHelp
{
    template<typename T = ccHelp::obj*, typename FACTORY = std::function<T()>, typename HANDLE = std::function<void(T)>>
    class ObjectPool : public ccHelp::obj
    {
    private:
        void updateIdleList()
        {
            while (mIdleObjs.size() > mMaxObj)
            {
                auto obj = mIdleObjs.back();
                mIdleObjs.pop_back();
                
                if (mCleaner)
                {
                    mCleaner(obj);
                }
            }
        }
        
    private:
        std::list<T> mIdleObjs;
        hset<T> mBorrowedObjs;
        
    public:
        ObjectPool(FACTORY factory) :
        mMaxObj(100), mFactory(factory) {}
        
        ObjectPool(FACTORY factory, HANDLE cleaner)
        : mMaxObj(100), mFactory(factory), mCleaner(cleaner) {}
        
        ~ObjectPool<T>()
        {
            for (auto obj : mBorrowedObjs)
            {
                if (mOnReturn)
                {
                    mOnReturn(obj);
                }
                
                if (mCleaner)
                {
                    mCleaner(obj);
                }
            }
            
            for (auto obj : mIdleObjs)
            {
                if (mCleaner)
                {
                    mCleaner(obj);
                }
            }
        }
        
        CC_SYNTHESIZE(uint, mMaxObj, MaxObject);
        CC_SYNTHESIZE_READONLY_PASS_BY_REF(FACTORY, mFactory, ObjectFactory);
        CC_SYNTHESIZE_PASS_BY_REF(HANDLE, mCleaner, ObjectCleaner);
        CC_SYNTHESIZE_PASS_BY_REF(HANDLE, mOnGet, OnGet);
        CC_SYNTHESIZE_PASS_BY_REF(HANDLE, mOnReturn, OnReturn);
        
        T getObj()
        {
            if (mIdleObjs.empty())
            {
                mIdleObjs.push_back(mFactory());
            }
            
            auto ret = mIdleObjs.back();
            mIdleObjs.pop_back();
            mBorrowedObjs.insert(ret);
            
            if (mOnGet)
            {
                mOnGet(ret);
            }
            
            return ret;
        }
        
        template <typename TT>
        TT get()
        {
            return static_cast<T>(this->getObj());
        }
        
        void returnObj(T obj)
        {
            auto it = mBorrowedObjs.find(obj);
            if (it == mBorrowedObjs.end())
                return; // invalid object
            
            mBorrowedObjs.erase(it);
            mIdleObjs.push_back(obj);
            
            if (mOnReturn)
            {
                mOnReturn(obj);
            }
            
            updateIdleList();
        }
        
        void returnAllObj()
        {
            auto copy = mBorrowedObjs;
            for (T obj : copy)
            {
                returnObj(obj);
            }
        }
    };
}