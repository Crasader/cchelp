//
//  BasicLayout.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#include "LayoutHelper.h"
#include "GroupLayout.h"
#include "Utils.h"
#include <string>
#include <sstream>

#include <limits>

USING_NS_CC;
using namespace std;

namespace ccHelp {
    hmap<std::string, Layout::Parameter> LayoutHelper::Cache;
    hmap<std::string, LayoutQuery> LayoutHelper::Queries;
    
    Node* LayoutHelper::queryNode(cocos2d::Node *root, const string &query)
    {
        if (query.empty())
            return root;
        
        // try custome query
        auto it = Queries.find(query);
        if (it != Queries.end())
        {
            Node *ret = it->second(root);
            if (ret)
                return ret;
        }
        
        stringstream ss(query);
        
        string nodeName;
        Node *qNode = root;
        bool checkRoot = false;
        
        while (std::getline(ss, nodeName, '.'))
        {
            if (!checkRoot && (nodeName == "this" || nodeName == "root"))
            {
                checkRoot = true;
                continue;
            }
            
            qNode = qNode->getChildByName(nodeName);
            
            if (!qNode)
                break;
        }
        
        return qNode;
    }
    
    void LayoutHelper::loadLayoutFile(const std::string &file)
    {
        Json::Reader reader;
        Layout::Parameter param;
        
        string content = FileUtils::getInstance()->getStringFromFile(file);
        
        if (!reader.parse(content, param))
            return;
        
        Cache[file] = param;
    }
    
    void LayoutHelper::apply(cocos2d::Node *root, const std::string &file)
    {
        auto ite = Cache.find(file);
        if (ite == Cache.end())
        {
            // not found, try to load
            loadLayoutFile(file);
            // get again to make sure the load ok
            ite = Cache.find(file);
        }
        
        if (ite == Cache.end())
        {
            // the file invalid
            return;
        }
        
        // ok, we got the layot param, do layout by group layout:
        GroupLayout::getInstance()->doLayout(root, ite->second);
    }
    
    void LayoutHelper::applyJsonString(cocos2d::Node *root, const std::string jsParam)
    {
        // no cache for this mode
        Json::Reader reader;
        Json::Value js;
        
        if (!reader.parse(jsParam, js))
            return; // no layout
        
        GroupLayout::getInstance()->doLayout(root, js);
    }
    
    void LayoutHelper::applyJson(cocos2d::Node *root, const Layout::Parameter &p)
    {
        GroupLayout::getInstance()->doLayout(root, p);
    }
    
    const Layout::Parameter& LayoutHelper::getLayout(const std::string &file)
    {
        auto ite = Cache.find(file);
        if (ite == Cache.end())
        {
            // not found, try to load
            loadLayoutFile(file);
            // get again to make sure the load ok
            ite = Cache.find(file);
        }
        
        if (ite == Cache.end())
        {
            return Json::Value::null;
        }
        
        return ite->second;
    }
    
    bool LayoutHelper::asFloat(const Layout::Parameter &p, float &f)
    {
        switch (p.type()) {
            case Json::ValueType::intValue:
            case Json::ValueType::uintValue:
            case Json::ValueType::realValue:
            {
                f = p.asFloat();
                return true;
            }
                
            case Json::ValueType::stringValue:
            {
                auto s = p.asString();
                float ratio = 1;
                if (s[s.length() - 1] == '%')
                {
                    s.pop_back();
                    ratio = 100;
                }
                
                sscanf(s.c_str(), "%f", &f);
                f /= ratio;
                return true;
            }
                break;
                
            default:
                break;
        }
        
        return false;
    }
    
    bool LayoutHelper::asColor3(const Layout::Parameter &p, cocos2d::Color3B &c)
    {
        if (!p.isString())
            return false;
        
        string s = p.asString();
        for (auto &c : s)
        {
            c = toupper(c);
        }
        
        c = ccHelp::Utils::colorFromText<Color3B>(s);
        if (c != Color3B::BLACK || s == "BLACK")
            return true;
        
        if (s[0] == '#')
            s.erase(s.begin());
        
        if (s.length() != 6)
            return false;
        
        stringstream ss;
        ss<<std::hex<<s;
        int cc;
        ss>>cc;
        
        c.b = (cc) & 0x000000ff;
        c.g = (cc>>8) & 0x000000ff;
        c.r = (cc>>16) & 0x000000ff;
        
        return true;
    }
    
    bool LayoutHelper::asColor4(const Layout::Parameter &p, cocos2d::Color4B &c)
    {
        if (!p.isString())
            return false;
        
        string s = p.asString();
        for (auto &c : s)
        {
            c = toupper(c);
        }
        
        c = ccHelp::Utils::colorFromText<Color4B>(s);
        if (c != Color3B::BLACK || s == "BLACK")
            return true;
        
        if (s[0] == '#')
            s.erase(s.begin());
        
        if (s.length() != 8)
            return false;
        
        stringstream ss;
        ss<<std::hex<<s;
        int cc;
        ss>>cc;
        
        c.a = (cc) & 0x000000ff;
        c.b = (cc>>8) & 0x000000ff;
        c.g = (cc>>16) & 0x000000ff;
        c.r = (cc>>24) & 0x000000ff;
        
        return true;
    }
    
    bool LayoutHelper::asUIResType(const Layout::Parameter &p, ui::TextureResType &t)
    {
        if (!p.isString())
            return false;
        
        string s = p.asString();
        for (char &c : s) {c = tolower(c);}
        
        if (s == "local")
        {
            t = ui::TextureResType::LOCAL;
            return true;
        }
        
        if (s == "plist")
        {
            t = ui::TextureResType::PLIST;
            return true;
        }
        
        return false;
    }
    
    string LayoutHelper::chooseMember(const Layout::Parameter &par, uint n, ...)
    {
        va_list ap;
        va_start(ap, n);
        
        for (uint i = 0; i < n; ++i)
        {
            const char *p = va_arg(ap, const char *);
            if (par.isMember(p))
                return p;
        }
        
        va_end(ap);
        
        return "";
    }
}