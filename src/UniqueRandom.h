#pragma once
#include "Def.h"

namespace ccHelp {
    class UniqueRandomFull
    {
    private:
        uint index;
        uint theOffset;
        
        static inline uint permute(uint x);
        
    public:
        inline UniqueRandomFull(uint _index, uint _seed);
        inline uint next();
    };
    
    class UniqueRandom
    {
    private:
        static uint INVALID;
        
    private:
        uint upperBound;
        uint prime;
        
        uint index;
        uint theOffset;
        
        void init(uint _bound, uint _prime, uint _index, uint _seed);
        uint permute(uint x);
        
        static uint findPrime(uint subBound);
        static bool isPrime(uint n);
        
    public:
        UniqueRandom(uint bound);
        UniqueRandom(uint bound, uint _index, uint _seed);
        UniqueRandom(uint bound, uint _prime, uint _index, uint _seed);
        
        uint next();
    };
}