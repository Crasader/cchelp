//
//  UVector.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/24/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"
#include <memory>
#include "msgpack/msgpack_helper.hpp"

namespace strife {
    
    template <typename T>
    class UVector : public std::vector<std::unique_ptr<T>>
    {
    public:
        template <typename Packer>
        void msgpack_pack(Packer& pk) const
        {
            pk.pack_array(this->size());
            for (auto &up : (*this))
            {
                pk.pack(*up);
            }
        }
        
        inline void msgpack_unpack(msgpack::object o)
        {
            if(o.type != msgpack::type::ARRAY) { throw msgpack::type_error(); }
            this->clear();
            this->reserve(o.via.array.size);
            if(o.via.array.size > 0) {
                msgpack::object* p = o.via.array.ptr;
                msgpack::object* const pend = o.via.array.ptr + o.via.array.size;
                do {
                    T* it = new T();
                    p->convert(it);
                    ++p;
                    
                    std::unique_ptr<T> ptr(it);
                    this->push_back(std::move(ptr));
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
                o->via.array.ptr = (MSGPACK_OBJECT*) z->malloc(sizeof(MSGPACK_OBJECT)*this->size());
                o->via.array.size = this->size();
                
                for (long i = 0l; i < this->size(); ++i)
                {
                    o->via.array[i] = object(*(this->at(i)), z);
                }
            }
        }
        
        void push_back_ptr(T *p)
        {
            std::unique_ptr<T> ptr(p);
            this->push_back(std::move(ptr));
        }
    };
}