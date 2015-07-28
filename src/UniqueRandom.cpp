//
//  UniqueRandom.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/28/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "UniqueRandom.h"
#include "Utils.h"

namespace ccHelp {
    uint UniqueRandomFull::permute(uint x)
    {
        static const uint prime = 4294967291u;
        if (x >= prime)
            return x;  // The 5 integers out of range are mapped to themselves.
        uint residue = ((unsigned long long) x * x) % prime;
        return (x <= prime / 2) ? residue : prime - residue;
    }
    
    UniqueRandomFull::UniqueRandomFull(uint _index, uint _seed)
    {
        index = _index;
        theOffset = permute(permute(_seed) + 0x66AD6D7);
    }
    
    uint UniqueRandomFull::next()
    {
        return permute((permute(index++) + theOffset) ^ 0x4DF9B9E);
    }
    
    uint UniqueRandom::INVALID = 0xffffffff;
    
    void UniqueRandom::init(uint _bound, uint _prime, uint _index, uint _seed)
    {
        this->upperBound = _bound;
        this->prime = _prime;
        this->index = _index;
        this->theOffset = permute(permute(_seed));
        this->theOffset %= this->upperBound;
    }
    
    uint UniqueRandom::permute(uint x)
    {
        if (x >= prime)
            return INVALID; // you are random too much, return invalid number
        
        uint residue = ((unsigned long long) x * x) % prime;
        return ((x<<1) <= prime) ? residue : prime - residue;
    }
    
    UniqueRandom::UniqueRandom(uint bound)
    {
        this->init(bound, findPrime(bound), 0, (uint) (Utils::time() % bound));
    }
    
    UniqueRandom::UniqueRandom(uint bound, uint _index, uint _seed)
    {
        this->init(bound, findPrime(bound), _index, _seed);
    }
    
    UniqueRandom::UniqueRandom(uint bound, uint _prime, uint _index, uint _seed)
    {
        this->init(bound, _prime, _index, _seed);
    }
    
    uint UniqueRandom::next()
    {
        uint r = permute(index++) ^ theOffset;
        return (r < upperBound)?r:((r == (INVALID ^ theOffset))?INVALID:next());
    }
    
    uint UniqueRandom::findPrime(uint subBound)
    {
        if (subBound < 2)
            return INVALID;
        
        if (subBound == 2 || subBound == 3)
            return subBound;
        
        subBound += 3 - (subBound % 4);
        if (!(subBound) % 2)
        {
            subBound += 3;
        }
        
        while (!isPrime(subBound)) {
            subBound += 4;
        }
        
        return subBound;
    }
    
    bool UniqueRandom::isPrime(uint n)
    {
        if (n < 2)
            return false;
        
        if (n == 2)
            return true;
        
        if (!(n % 2))
            return false;
        
        for (int i = 3; i * i <= n; i += 2)
        {
            if (!(n % i))
                return false;
        }
        
        return true;
    }
}