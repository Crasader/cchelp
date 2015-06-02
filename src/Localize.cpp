//
//  Localize.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//

#include "Localize.h"
#include "cocos2d.h"
#include "jsoncpp/jsonserialization.h"

using namespace std;
USING_NS_CC;

namespace ccHelp {
    Localize::Localize()
    {
        this->cLang = "en";
    }
    
    void Localize::reloadData()
    {
        this->texts.clear();
        
        if (this->languages.find(cLang) == this->languages.end())
            return;
        
        string langFile = this->languages[cLang];
        
        string content = FileUtils::getInstance()->getStringFromFile(langFile);
        Json::Value json;
        Json::Reader reader;
        bool parseSucc = reader.parse(content, json);
        
        if (!parseSucc)
            return;
        
        Json::type::deserialize(json, this->texts);
    }
    
    void Localize::loadLanguageMapping(const std::string &mappingFile)
    {
        string content = FileUtils::getInstance()->getStringFromFile(mappingFile);
        Json::Value json;
        Json::Reader reader;
        bool parseSucc = reader.parse(content, json);
        
        if (!parseSucc)
            return;
        
        hmap<string, string> data;
        Json::type::deserialize(json, data);
        
        for (auto lang : data)
        {
            this->languages[lang.first] = lang.second;
        }
    }
    
    Localize SHARED_LOCALIZE;
}