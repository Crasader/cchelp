//
//  Hash.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/8/15.
//
//

#pragma once
#include "../external/xxhash/xxhash.h"

namespace ccHelp {
    template <typename T>
    struct Hasher
    {
    public:
        int operator()(const T& t) const
        {
            return XXH32(&t, sizeof(T), 0);
        }
    };
}
