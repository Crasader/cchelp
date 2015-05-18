//
//  vsson.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/18/15.
//
//

#pragma once
#include <string>
#include <unordered_map>

using std::string;

namespace vsson
{
    class VSSValue
    {
    private:
        string rootString;
        
    public:
        VSSValue() = default;
        VSSValue(const string &s);
        VSSValue(const VSSValue &vssv) = default;
        VSSValue& operator=(const VSSValue &vssv) = default;
        
        const string& asString() const;
        void set(const string &s);
        
        bool isInt() const;
        int asInt() const;
        bool parseInt(int &i) const;
        
        bool isReal() const;
        float asReal() const;
        bool parseReal(float &f) const;
        
    public:
        static VSSValue EMPTY;
    };
    
    class VSSObject
    {
    private:
        std::unordered_map<string, VSSValue> namedField;
        std::vector<VSSValue> indexedField;
        
    public:
        VSSObject() = default;
        VSSObject(const VSSObject &vsso) = default;
        VSSObject& operator=(const VSSObject &vsso) = default;
        
        const VSSValue& operator[](const string &name) const;
        VSSValue& operator[](const string &name);
        
        const VSSValue& operator[](unsigned int idx) const;
        VSSValue& operator[](unsigned int idx);
        
        void put(const string &name, const VSSValue &vssv);
        unsigned int push(const VSSValue &vssv);
        
        void clear();
    };
    
    class VSSParser
    {
    public:
        static VSSObject parse(const string &s);
        static void parse(const string &s, VSSObject &vsso);
        
        
    };
}