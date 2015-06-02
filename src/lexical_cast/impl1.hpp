//
//  impl1.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/4/15.
//
//

#ifndef LEXICAL_CAST_IMPL1
#define LEXICAL_CAST_IMPL1

#include "lc_def.hpp"

#include <string>
#include <sstream>
#include <limits>

namespace ccHelp {
    
    template<typename O>
    O lexical_cast(const std::string &inp)
    {
        std::stringstream ss(inp);
        O outp;
        
        ss>>outp;
        
        return outp;
    }
}
#endif
