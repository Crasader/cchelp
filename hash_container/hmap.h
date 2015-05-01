#ifndef __JSONSER_TYPE_HASH_MAP_H__
#define __JSONSER_TYPE_HASH_MAP_H__

#include "cocos2d.h"
#include <jsoncpp/json2/json.h>
#include <string>
#include "jsoncpp/strserialization.hpp"
#include "jsoncpp/def.hpp"

using std::string;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
/*#include <hash_map>
template <typename K, typename V, typename H = std::hash<K>>
using hmap = std::hash_map<K, V, H>;*/
#include <unordered_map>
template <typename K, typename V, typename H = std::hash<K>>
using hmap = std::unordered_map<K, V, H>;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include <unordered_map>
template <typename K, typename V, typename H = std::hash<K>>
using hmap = std::unordered_map<K, V, H>;
#else
#include <tr1/unordered_map>
template <typename K, typename V, typename H = std::hash<K>>
using hmap = std::tr1::unordered_map<K, V, H>;
#endif

// support json serialization
namespace Json {
    namespace type
    {
        template <typename V>
        inline bool deserialize(const Json::Value &j, hmap<string, V> &v)
        {
            v.clear();
            if (j.isObject())
            {
                for (ValueIterator it = j.begin(); it != j.end(); ++it)
                {
                    string key = it.key().asString();
                    V val;
                    Json::type::deserialize((*it), val);
                    v[key] = val;
                }
                return true;
            }
            
            return false;
        }
        
        
        template <typename V>
        inline Json::Value serialize(const hmap<string, V> &v)
        {
            Value jVal;
            for (auto it = v.cbegin(); it != v.cend(); ++it)
            {
                jVal[it->first] = Json::type::serialize(it->second);
            }
            
            return jVal;
        }
        
        template <typename K, typename V>
        inline bool deserialize(const Json::Value &j, hmap<K, V> &v)
        {
            v.clear();
            if (j.isObject())
            {
                for (Json::ValueIterator it = j.begin(); it != j.end(); ++it)
                {
                    K key;
                    Json::type::strDeserialize(it.key().asString(), key);
                    V val;
                    Json::type::deserialize((*it), val);
                    v[key] = val;
                }
                return true;
            }
            
            return false;
        }
        
        
        template <typename K, typename V>
        inline Json::Value serialize(const hmap<K, V> &v)
        {
            Value jVal;
            for (auto it = v.cbegin(); it != v.cend(); ++it)
            {
                std::string key = Json::type::strSerialize(it->first);
                jVal[key] = Json::type::serialize(it->second);
            }
            
            return jVal;
        }
    }
}  // namespace Json

#endif
