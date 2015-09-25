//
//  msgpack_helper.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/24/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "msgpack.h"
#include "Macro/BINARY.hpp"

namespace msgpack {
    enum MSGPACK_METHOD : ubyte
    {
        PACK_BEFORE = bin<0000>::value,
        UNPACK_BEFORE = bin<0100>::value,
        OBJECT_BEFORE = bin<1010>::value,
        PACK_AFTER = bin<0011>::value,
        UNPACK_AFTER = bin<0101>::value,
        OBJECT_AFTER = bin<1011>::value,
        PACK = PACK_BEFORE | PACK_AFTER,
        UNPACK = UNPACK_BEFORE | UNPACK_AFTER,
        OBJECT = OBJECT_BEFORE | OBJECT_AFTER
    };
    
    template<typename T>
    T* ccast(const T *t) {return const_cast<T*>(t);}
}

#define CCH_MSGPACK_DEFINE(...) \
\
template <typename Packer> \
void msgpack_pack(Packer& pk) const \
{ \
    msgpack::ccast(this)->msgpack_callback(msgpack::PACK_BEFORE); \
    msgpack::type::make_define(__VA_ARGS__).msgpack_pack(pk); \
    msgpack::ccast(this)->msgpack_callback(msgpack::PACK_AFTER); \
} \
\
inline void msgpack_unpack(msgpack::object o) \
{ \
    msgpack_callback(msgpack::UNPACK_BEFORE); \
    msgpack::type::make_define(__VA_ARGS__).msgpack_unpack(o); \
    msgpack_callback(msgpack::UNPACK_AFTER); \
} \
\
template <typename MSGPACK_OBJECT> \
void msgpack_object(MSGPACK_OBJECT* o, msgpack::zone* z) const \
{ \
    msgpack::ccast(this)->msgpack_callback(msgpack::OBJECT_BEFORE); \
    msgpack::type::make_define(__VA_ARGS__).msgpack_object(o, z); \
    msgpack::ccast(this)->msgpack_callback(msgpack::OBJECT_AFTER); \
} \
 \
void msgpack_callback(msgpack::MSGPACK_METHOD method)