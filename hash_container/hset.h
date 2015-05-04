#ifndef __JSONSER_TYPE_HASH_SET_H__
#define __JSONSER_TYPE_HASH_SET_H__

#include "cocos2d.h"
#include <jsoncpp/json2/json.h>
#include <string>
#include "jsoncpp/strserialization.hpp"
#include "jsoncpp/def.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
/*#include <hash_set>
template <typename T, typename H = std::hash<T>>
using hset = std::hash_set<T, H>;*/
#include <unordered_set>
template <typename T, typename H = std::hash<T>>
using hset = std::unordered_set<T, H>;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include <unordered_set>
template <typename T, typename H = std::hash<T>>
using hset = std::unordered_set<T, H>;
#else
/*#include <tr1/unordered_set >
template <typename T, typename H = std::hash<T>>
using hset = std::tr1::unordered_set<T, H>;*/
#include <unordered_set>
template <typename T, typename H = std::hash<T>>
using hset = std::unordered_set<T, H>;
#endif

// support json serialization
namespace Json {
    namespace type
    {
        template <typename T>
        inline bool deserialize(const Json::Value &j, hset<T> &v)
        {
            v.clear();
            if (j.isArray())
            {
                v.reserve(j.size());
                for (unsigned int i = 0; i < j.size(); ++i)
                {
                    hset<T> val;
                    Json::type::deserialize(j[i], val);
                    v.push_back(val);
                }
                return true;
            }
            
            return false;
        }
        
        
        template <typename T>
        inline Json::Value serialize(const hset<T> &v)
        {
            Json::Value jVal;
            for (auto &vi : v)
            {
                jVal.append(Json::type::serialize(vi));
            }
            
            return jVal;
        }
    }
}  // namespace Json

#endif
