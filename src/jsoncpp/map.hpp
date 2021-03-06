#ifndef __JSONSER_TYPE_MAP_H__
#define __JSONSER_TYPE_MAP_H__

#include "def.hpp"
#include <map>

namespace Json {
	namespace type
	{
		template <typename V>
		inline bool deserialize(const Json::Value &j, typename std::map<string, V> &v)
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
		inline Json::Value serialize(typename std::map<string, V> const &v)
		{
			Value jVal;
			for (typename std::map<string, V>::iterator it = v.cbegin(); it != v.cend(); ++it)
			{
				jVal[it->first] = Json::type::serialize(it->second);
			}

			return jVal;
		}

		template <typename K, typename V>
		inline bool deserialize(const Json::Value &j, typename std::map<K, V> &v)
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
		inline Json::Value serialize(typename std::map<K, V> const &v)
		{
			Value jVal;
			for (typename std::map<K, V>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
			{
				std::string key = Json::type::strSerialize(it->first);
				jVal[key] = Json::type::serialize(it->second);
			}

			return jVal;
		}
	}
}  // namespace Json

#endif
