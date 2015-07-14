#pragma once
#include "Def.h"

namespace ccHelp {
    class UniqueRandom
    {
    private:
        uint index;
        uint theOffset;
        
        static inline uint permute(uint x)
        {
            static const uint prime = 4294967291u;
            if (x >= prime)
                return x;  // The 5 integers out of range are mapped to themselves.
            uint residue = ((unsigned long long) x * x) % prime;
            return (x <= prime / 2) ? residue : prime - residue;
        }
        
    public:
        inline UniqueRandom(uint _index, uint _seed)
        {
            index = _index;
            theOffset = permute(permute(_seed) + 0x66AD6D7);
        }
        
        inline uint next()
        {
            return permute((permute(index++) + theOffset) ^ 0x4DF9B9E);
        }
    };
}