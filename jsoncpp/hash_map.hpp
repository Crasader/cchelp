#ifndef __JSONSER_TYPE_HASH_MAP_H__
#define __JSONSER_TYPE_HASH_MAP_H__
#include "def.hpp"
#include "hash_container/hmap.h"

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
        
        template <typename V, typename H>
        inline bool deserialize(const Json::Value &j, hmap<string, V, H> &v)
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
        
        
        template <typename V, typename H>
        inline Json::Value serialize(const hmap<string, V, H> &v)
        {
            Value jVal;
            for (auto it = v.cbegin(); it != v.cend(); ++it)
            {
                jVal[it->first] = Json::type::serialize(it->second);
            }
            
            return jVal;
        }
        
        template <typename K, typename V, typename H>
        inline bool deserialize(const Json::Value &j, hmap<K, V, H> &v)
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
        
        
        template <typename K, typename V, typename H>
        inline Json::Value serialize(const hmap<K, V, H> &v)
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
