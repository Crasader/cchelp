//
//  msgpack_hmap.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/9/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once

#include "msgpack/msgpack/object.hpp"
#include <unordered_set>

namespace msgpack {
    
    
    template <typename T, typename H = std::hash<T>>
    inline std::unordered_set<T, H>& operator>> (object o, std::unordered_set<T, H>& v)
    {
        if(o.type != type::ARRAY) { throw type_error(); }
        object* p = o.via.array.ptr + o.via.array.size;
        object* const pbegin = o.via.array.ptr;
        while(p > pbegin) {
            --p;
            v.insert(p->as<T>());
        }
        return v;
    }
    
    template <typename Stream, typename T, typename H = std::hash<T>>
    inline packer<Stream>& operator<< (packer<Stream>& o, const std::unordered_set<T, H>& v)
    {
        o.pack_array(v.size());
        for(typename std::unordered_set<T, H>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(*it);
        }
        return o;
    }
    
    template <typename T, typename H = std::hash<T>>
    inline void operator<< (object::with_zone& o, const std::unordered_set<T, H>& v)
    {
        o.type = type::ARRAY;
        if(v.empty()) {
            o.via.array.ptr = NULL;
            o.via.array.size = 0;
        } else {
            object* p = (object*)o.zone->malloc(sizeof(object)*v.size());
            object* const pend = p + v.size();
            o.via.array.ptr = p;
            o.via.array.size = v.size();
            typename std::unordered_set<T, H>::const_iterator it(v.begin());
            do {
                *p = object(*it, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
    
    
    template <typename T, typename H = std::hash<T>>
    inline std::unordered_multiset<T, H>& operator>> (object o, std::unordered_multiset<T, H>& v)
    {
        if(o.type != type::ARRAY) { throw type_error(); }
        object* p = o.via.array.ptr + o.via.array.size;
        object* const pbegin = o.via.array.ptr;
        while(p > pbegin) {
            --p;
            v.insert(p->as<T>());
        }
        return v;
    }
    
    template <typename Stream, typename T, typename H = std::hash<T>>
    inline packer<Stream>& operator<< (packer<Stream>& o, const std::unordered_multiset<T, H>& v)
    {
        o.pack_array(v.size());
        for(typename std::unordered_multiset<T, H>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(*it);
        }
        return o;
    }
    
    template <typename T, typename H = std::hash<T>>
    inline void operator<< (object::with_zone& o, const std::unordered_multiset<T, H>& v)
    {
        o.type = type::ARRAY;
        if(v.empty()) {
            o.via.array.ptr = NULL;
            o.via.array.size = 0;
        } else {
            object* p = (object*)o.zone->malloc(sizeof(object)*v.size());
            object* const pend = p + v.size();
            o.via.array.ptr = p;
            o.via.array.size = v.size();
            typename std::unordered_multiset<T, H>::const_iterator it(v.begin());
            do {
                *p = object(*it, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
}  // namespace msgpack