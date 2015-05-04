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
    O lexical_cast(const std::string &inp);
    
    template<> inline int lexical_cast<int>(const std::string &inp)
    {
        std::stringstream ss(inp);
        int outp;
        ss>>outp;
        
        return outp;
    }
    
    template<> inline unsigned int lexical_cast<unsigned int>(const std::string &inp)
    {
        std::stringstream ss(inp);
        unsigned int outp;
        ss>>outp;
        
        return outp;
    }
    
    template<> inline float lexical_cast<float>(const std::string &inp)
    {
        std::stringstream ss(inp);
        float outp;
        ss>>outp;
        
        return outp;
    }

}
#endif
