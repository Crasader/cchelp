//
//  UMap.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/29/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include <memory>
#include "hash_container/hmap.h"
#include "msgpack/msgpack_helper.hpp"

namespace ccHelp {
    
    template <typename K, typename V, typename H = std::hash<K>>
    class UMap : public hmap<K, std::unique_ptr<V>, H>
    {
    public:
        template <typename Packer>
        void msgpack_pack(Packer& pk) const
        {
            pk.pack_array(2 * this->size());
            for (auto &it : (*this))
            {
                pk.pack(it.first);
                pk.pack(*(it.second));
            }
        }
        
        inline void msgpack_unpack(msgpack::object o)
        {
            if(o.type != msgpack::type::ARRAY) { throw msgpack::type_error(); }
            this->clear();
            if(o.via.array.size > 0) {
                msgpack::object* p = o.via.array.ptr;
                msgpack::object* const pend = o.via.array.ptr + o.via.array.size;
                do {
                    K k;
                    p->convert(&k);
                    ++p;
                    
                    V* v = new V();
                    p->convert(v);
                    ++p;
                    
                    std::unique_ptr<V> ptr(v);
                    this->insert(std::make_pair(k, std::move(ptr)));
                } while(p < pend);
            }
        }
        
        template <typename MSGPACK_OBJECT>
        void msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const
        {
            o->type = msgpack::type::ARRAY;
            if(this->empty()) {
                o->via.array.ptr = nullptr;
                o->via.array.size = 0;
            } else {
                o->via.array.ptr = (MSGPACK_OBJECT*) z->malloc(2 * sizeof(MSGPACK_OBJECT) * this->size());
                o->via.array.size = 2 * this->size();
                
                long i = 0l;
                for (auto &it : *this)
                {
                    o->via.array[i++] = object(it->first, z);
                    o->via.array[i++] = object(*(it->second), z);
                }
            }
        }
        
        void insert_ptr(K k, V *p)
        {
            std::unique_ptr<V> ptr(p);
            this->insert(std::make_pair(k, std::move(ptr)));
        }
    };
}