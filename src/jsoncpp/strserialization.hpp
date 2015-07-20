#ifndef __JSONSER_STR_H__
#define __JSONSER_STR_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
		template <typename V>
		inline std::string strSerialize(const V &v)
        {
            std::stringstream ss;
            ss<<v;
            
            return ss.str();
        }
        
		template <typename V>
		inline bool strDeserialize(const std::string &s, V &v)
        {
            std::stringstream ss(s);
            ss>>v;
            
            return !ss.fail();
        }
	}

}  // namespace Json

template<typename V>
inline std::string toString(const V &v)
{
    return Json::type::strSerialize(v);
}

template<typename V>
inline V fromString(const std::string &s)
{
    V v;
    Json::type::strDeserialize(s, v);
    return v;
}

#define ENUM_STR_SERIALIZATION_DECL(TYPE) \
namespace Json { \
namespace type \
{ \
template<> \
std::string strSerialize(const TYPE &v); \
\
template<> \
bool strDeserialize(const std::string &s, TYPE &v); \
}\
}

#define ENUM_TO_STRING(TYPE) \
template<> inline std::string toString(const TYPE &v) {return Json::type::strSerialize(v);} \
template<> inline TYPE fromString(const string &s) {TYPE v; Json::type::strDeserialize(s, v); return v;}

#define ENUM_STR_SERIALIZATION_IMPL(TOKEN, TYPE, VAR) \
namespace Json { \
namespace type \
{ \
hmap<TYPE, std::string, ccHelp::Hasher<TYPE>> __enum_str_map_##TOKEN; \
hmap<std::string, TYPE> __enum_str_map_##TOKEN##Rev; \
\
void __enum_str_map_##TOKEN##_setup(hmap<TYPE, std::string, ccHelp::Hasher<TYPE>>&); \
\
void __enum_str_map_##TOKEN##_init() \
{ \
if (__enum_str_map_##TOKEN.empty()) \
{ \
__enum_str_map_##TOKEN##_setup(__enum_str_map_##TOKEN); \
\
for (auto it : __enum_str_map_##TOKEN) \
{ \
__enum_str_map_##TOKEN##Rev[it.second] = it.first; \
} \
} \
} \
\
template<> \
std::string strSerialize(const TYPE &v) \
{ \
__enum_str_map_##TOKEN##_init(); \
\
return __enum_str_map_##TOKEN[v]; \
} \
\
template<> \
bool strDeserialize(const std::string &s, TYPE &v) \
{ \
__enum_str_map_##TOKEN##_init(); \
\
v = __enum_str_map_##TOKEN##Rev[s]; \
return true;\
}\
}\
} \
\
void Json::type::__enum_str_map_##TOKEN##_setup(hmap<TYPE, std::string, ccHelp::Hasher<TYPE>> &VAR)

#endif
