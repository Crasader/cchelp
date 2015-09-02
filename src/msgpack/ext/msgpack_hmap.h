//
//  msgpack_hmap.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/9/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once

#include "msgpack/msgpack/object.hpp"
#include <unordered_map>

namespace msgpack {
    
    
    template <typename K, typename V, typename H = std::hash<K>>
    inline std::unordered_map<K, V, H> operator>> (object o, std::unordered_map<K, V, H>& v)
    {
        if(o.type != type::MAP) { throw type_error(); }
        object_kv* p(o.via.map.ptr);
        object_kv* const pend(o.via.map.ptr + o.via.map.size);
        for(; p != pend; ++p) {
            K key;
            p->key.convert(&key);
            p->val.convert(&v[key]);
        }
        return v;
    }
    
    template <typename Stream, typename K, typename V, typename H = std::hash<K>>
    inline packer<Stream>& operator<< (packer<Stream>& o, const std::unordered_map<K, V, H>& v)
    {
        o.pack_map(v.size());
        for(typename std::unordered_map<K, V, H>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(it->first);
            o.pack(it->second);
        }
        return o;
    }
    
    template <typename K, typename V, typename H = std::hash<K>>
    inline void operator<< (object::with_zone& o, const std::unordered_map<K, V, H>& v)
    {
        o.type = type::MAP;
        if(v.empty()) {
            o.via.map.ptr  = NULL;
            o.via.map.size = 0;
        } else {
            object_kv* p = (object_kv*)o.zone->malloc(sizeof(object_kv)*v.size());
            object_kv* const pend = p + v.size();
            o.via.map.ptr  = p;
            o.via.map.size = v.size();
            typename std::unordered_map<K, V, H>::const_iterator it(v.begin());
            do {
                p->key = object(it->first, o.zone);
                p->val = object(it->second, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
    
    
    template <typename K, typename V, typename H = std::hash<K>>
    inline std::unordered_multimap<K, V, H> operator>> (object o, std::unordered_multimap<K, V, H>& v)
    {
        if(o.type != type::MAP) { throw type_error(); }
        object_kv* p(o.via.map.ptr);
        object_kv* const pend(o.via.map.ptr + o.via.map.size);
        for(; p != pend; ++p) {
            std::pair<K, V> value;
            p->key.convert(&value.first);
            p->val.convert(&value.second);
            v.insert(value);
        }
        return v;
    }
    
    template <typename Stream, typename K, typename V, typename H = std::hash<K>>
    inline packer<Stream>& operator<< (packer<Stream>& o, const std::unordered_multimap<K, V, H>& v)
    {
        o.pack_map(v.size());
        for(typename std::unordered_multimap<K, V, H>::const_iterator it(v.begin()), it_end(v.end());
            it != it_end; ++it) {
            o.pack(it->first);
            o.pack(it->second);
        }
        return o;
    }
    
    template <typename K, typename V, typename H = std::hash<K>>
    inline void operator<< (object::with_zone& o, const std::unordered_multimap<K, V, H>& v)
    {
        o.type = type::MAP;
        if(v.empty()) {
            o.via.map.ptr  = NULL;
            o.via.map.size = 0;
        } else {
            object_kv* p = (object_kv*)o.zone->malloc(sizeof(object_kv)*v.size());
            object_kv* const pend = p + v.size();
            o.via.map.ptr  = p;
            o.via.map.size = v.size();
            typename std::unordered_multimap<K, V, H>::const_iterator it(v.begin());
            do {
                p->key = object(it->first, o.zone);
                p->val = object(it->second, o.zone);
                ++p;
                ++it;
            } while(p < pend);
        }
    }
    
    
}  // namespace msgpack