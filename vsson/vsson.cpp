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
        std::stringstream ss(rootString);
        int i;
        
        ss>>i;
        
        return ss.good();
    }
    
    int VSSValue::asInt() const
    {
        std::stringstream ss(rootString);
        int i;
        
        ss>>i;
        return i;
    }
    
    bool VSSValue::isReal() const
    {
        std::stringstream ss(rootString);
        float f;
        
        ss>>f;
        
        return ss.good();
    }
    
    float VSSValue::asReal() const
    {
        std::stringstream ss(rootString);
        float f;
        
        ss>>f;
        return f;
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
