//
//  ContextValue.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/25/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

namespace ccHelp {
    
    template <typename T>
    ContextValue ContextValue::makeCustom(const T &v)
    {
        ContextValue cv;
        cv.type = CUSTOM_HOLDER;
        cv.vCustomHolder = new CustomHolder<T>(v);
        
        return cv;
    }
    
    template <typename T>
    bool ContextValue::asPointer(T *&p) const
    {
        if (type == VOID_POINTER)
        {
            p = static_cast<T*>(vVoidPointer);
            return true;
        }
        
        return false;
    }
    
    template <typename T>
    bool ContextValue::asCustom(T &t) const
    {
        if (type == CUSTOM_HOLDER)
        {
            auto *p = dynamic_cast<CustomHolder<T>*>(vCustomHolder);
            if (!p)
                return false;
            
            t = p->get();
            return true;
        }
        
        return false;
    }
    

}
