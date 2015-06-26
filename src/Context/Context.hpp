//
//  Context.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/26/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once

namespace ccHelp {
    template <typename T>
    Context& Context::putPointer(const std::string &k, T *v)
    {
        valueMap[k] = ContextValue((void *) v);
    }
    
    template <typename T>
    Context& Context::putCustom(const std::string &k, const T& v)
    {
        valueMap[k] = ContextValue::makeCustom<T>(v);
    }
    
    template <typename T>
    T* Context::getPointer(const std::string &k) const
    {
        return valueMap.at(k).asPointer<T>();
    }
    
    template <typename T>
    bool Context::getCustom(const std::string &k, T& t) const
    {
        return valueMap.at(k).asCustom<T>(t);
    }
}