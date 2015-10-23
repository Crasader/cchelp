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
    
    Node* LayoutHelper::queryNode(cocos2d::Node *root, string query)
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
        
        // check if query has special prefix
        if (query[0] == '+')
        {
            query = query.substr(1, query.length() - 1);
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
        Json::Value param;
        
        string content = FileUtils::getInstance()->getStringFromFile(file);
        
        if (!reader.parse(content, param))
        {
#if COCOS2D_DEBUG > 0
            CCASSERT(false, "Invalid json syntax");
#endif
            log("Invalid json syntax: %s", file.c_str());
            return;
        }
        
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
    
    void LayoutHelper::format(Node *root, const string &key, const Json::Value &js)
    {
        Json::Value par;
        par[key] = js;
        
        GroupLayout::getInstance()->doLayout(root, par);
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
            return Layout::Parameter::null;
        }
        
        return ite->second;
    }
    
    bool LayoutHelper::asFloat(const Layout::Parameter &p, float &f)
    {
        if (p.get(f))
            return true;
        
        string s;
        if (p.get(s))
        {
            float ff = 0;
            float ratio = 1;
            if (s[s.length() - 1] == '%')
            {
                s.pop_back();
                ratio = 100;
            }
            
            sscanf(s.c_str(), "%f", &ff);
            f = ff / ratio;
            return true;
        }
        
        return false;
    }
    
    bool LayoutHelper::asColor3(const Layout::Parameter &p, cocos2d::Color3B &c)
    {
        string s;
        if (!p.get(s))
            return false;
        
        s = Utils::toupper(s);
        
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
        string s;
        if (!p.get(s))
            return false;
        
        s = Utils::toupper(s);
        
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
    
    bool LayoutHelper::asUIResType(const string &res, ui::TextureResType &t)
    {
        auto s = Utils::tolower(res);
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
}