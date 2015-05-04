#pragma once
#include "cocos2d.h"

namespace ccHelp
{
    template<class T>
    class RefHolder
    {
    public:
        RefHolder(T *ref = nullptr)
        : ref(ref)
        {
            init();
        }
        
        RefHolder(const RefHolder<T> &refHolder)
        : ref(refHolder.ref)
        {
            init();
        }
        
        RefHolder<T>& operator=(const RefHolder<T>& refHolder)
        {
            CC_SAFE_RELEASE(this->ref);
            this->ref = refHolder.ref;
            init();
            
            return *this;
        }
        
        ~RefHolder()
        {
            CC_SAFE_RELEASE(this->ref);
        }
        
        inline const T* get() const
        {
            return ref;
        }
        
        inline T* get()
        {
            return ref;
        }
        
        inline T* operator()()
        {
            return ref;
        }
        
        inline const T* operator()() const
        {
            return ref;
        }
        
        inline T* operator->()
        {
            return ref;
        }
        
        inline const T* operator->() const
        {
            return ref;
        }
        
        inline T& operator*()
        {
            return *ref;
        }
        
        inline const T& operator*() const
        {
            return *ref;
        }
        
        inline bool operator==(const RefHolder<T> &r) const
        {
            return this->ref == r.ref;
        }
        
        inline bool operator==(const T *ref) const
        {
            return this->ref == ref;
        }
    private:
        T* ref;
        inline void init()
        {
            if (ref)
            {
                ref->retain();
            }
        }
    };
}

template <typename T>
using CCREF = ccHelp::RefHolder<T>;