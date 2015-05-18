//
//  vsson.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/18/15.
//
//

#include "vsson.h"
#include <sstream>

namespace vsson {
    VSSValue::VSSValue(const string &s)
    : rootString(s)
    {
    }
    
    const string& VSSValue::asString() const
    {
        return rootString;
    }
    
    void VSSValue::set(const string &s)
    {
        rootString = s;
    }
    
    bool VSSValue::isInt() const
    {
        int i;
        return parseInt(i);
    }
    
    int VSSValue::asInt() const
    {
        int i = 0;
        parseInt(i);
        return i;
    }
    
    bool VSSValue::parseInt(int &i) const
    {
        std::stringstream ss(rootString);
        ss>>i;
        
        return ss.good();
    }
    
    bool VSSValue::isReal() const
    {
        float f;
        return parseReal(f);
    }
    
    float VSSValue::asReal() const
    {
        float f = 0;
        parseReal(f);
        return f;
    }
    
    bool VSSValue::parseReal(float &f) const
    {
        std::stringstream ss(rootString);
        ss>>f;
        
        return ss.good();
    }
    
    const VSSValue& VSSObject::operator[](const string &name) const
    {
        return namedField.at(name);
    }
    
    VSSValue& VSSObject::operator[](const string &name)
    {
        return namedField.at(name);
    }
    
    const VSSValue& VSSObject::operator[](uint idx) const
    {
        return indexedField[idx];
    }
    
    VSSValue& VSSObject::operator[](unsigned int idx)
    {
        return indexedField[idx];
    }
    
    void VSSObject::put(const string &name, const vsson::VSSValue &vssv)
    {
        namedField[name] = vssv;
    }
    
    unsigned int VSSObject::push(const vsson::VSSValue &vssv)
    {
        indexedField.push_back(vssv);
        return indexedField.size() - 1;
    }
    
    void VSSObject::clear()
    {
        namedField.clear();
        indexedField.clear();
    }
    
    VSSObject VSSParser::parse(const string &s)
    {
        VSSObject vsso;
        
        parse(s, vsso);
        
        return vsso;
    }
    
    void VSSParser::parse(const string &s, vsson::VSSObject &vsso)
    {
        vsso.clear();
        
        std::stringstream ss(s);
        
        string field;
        
        while (std::getline(ss, field, '|'))
        {
            auto colonIndex = field.find(':');
            if (colonIndex == string::npos)
            {
                vsso.push(field);
            }
            else
            {
                vsso.put(field.substr(0, colonIndex), field.substr(colonIndex + 1, field.length() - colonIndex -1));
            }
        }
    }
}
