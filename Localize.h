//
//  Localize.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 3/31/15.
//
//

#ifndef __GodRage_Endless_Revamp__Localize__
#define __GodRage_Endless_Revamp__Localize__

#include <stdio.h>
#include <string>
#include <locale>
#include "hmap.h"

namespace ccHelp {
#ifdef CC_SUPPORT_UNICODE
    typedef wchar_t tchar;
    typedef std::wstring tstring;
#else
    typedef char tchar;
    typedef std::string tstring;
#endif
    
    class Localize
    {
    private:
        hmap<std::string, tstring> texts;
        hmap<std::string, std::string> languages;
        std::string cLang;
        
    public:
        Localize();
        
        void reloadData();
        
        void setLanguage(const std::string &lang)
        {
            this->cLang = lang;
            this->reloadData();
        }
        
        inline const std::string& getCurrentLanguage() const
        {
            return this->cLang;
        }
        
        inline void addLanguageMapping(const std::string &lang, const std::string &file)
        {
            this->languages[lang] = file;
        }
        
        inline const tstring& get(const string &txt)
        {
            auto it = this->texts.find(txt);
            if (it == this->texts.end())
                return txt;
            
            return it->second;
        }
        
        void loadLanguageMapping(const std::string &mappingFile);
    };
    
    extern Localize SHARED_LOCALIZE;
    inline const tstring& LOCAL(const std::string &txt)
    {
        return SHARED_LOCALIZE.get(txt);
    }
}

#endif /* defined(__GodRage_Endless_Revamp__Localize__) */
