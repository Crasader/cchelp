//
//  impl2.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/4/15.
//
//

#ifndef LEXICAL_CAST_IMPL2
#define LEXICAL_CAST_IMPL2

#include "lc_def.hpp"

#include <jsoncpp/json2/json.h>

namespace ccHelp {
    
    template<typename O>
    O lexical_cast(const Json::Value &inp);
    
    template<> inline float lexical_cast<float>(const Json::Value &inp)
    {
        if (inp.isNumeric())
        {
            return inp.asFloat();
        }
        else if (inp.isString())
        {
            return lexical_cast<float>(inp.asString());
        }
        
        return std::numeric_limits<float>::infinity();
    }
    
    template<> inline uint lexical_cast<uint>(const Json::Value &inp)
    {
        if (inp.isNumeric())
        {
            return inp.asUInt();
        }
        else if (inp.isString())
        {
            return lexical_cast<uint>(inp.asString());
        }
        
        return std::numeric_limits<uint>::infinity();
    }
}

#endif
