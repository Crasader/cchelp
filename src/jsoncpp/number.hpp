#ifndef __JSONSER_TYPE_UINT_H__
#define __JSONSER_TYPE_UINT_H__

#include "def.hpp"
#include <sstream>

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__

#define JSON_SER_DEFINE_CAST(type, json_check, json_as, cast) \
		__JSONSER_TEMPLATE inline bool deserialize(const Json::Value &j, type &v) \
		{ \
			if (j.json_check()) \
			{ \
				v = (type) j.json_as(); \
				return true; \
            } \
            else if (j.isString()) \
            { \
                std::stringstream ss(j.asString()); \
                ss>>v; \
                return true; \
            } \
            \
			return false; \
		} \
        \
		__JSONSER_TEMPLATE inline Json::Value serialize(const type &v) \
		{ \
			return Json::Value((cast) v); \
		}
        
#define JSON_SER_DEFINE(type, json_check, json_as) JSON_SER_DEFINE_CAST(type, json_check, json_as, type)
        
        JSON_SER_DEFINE(char, isNumeric, asInt);
        JSON_SER_DEFINE(unsigned char, isNumeric, asUInt);
        JSON_SER_DEFINE(short, isNumeric, asInt);
        JSON_SER_DEFINE(unsigned short, isNumeric, asUInt);
        JSON_SER_DEFINE(int, isNumeric, asInt);
        JSON_SER_DEFINE(unsigned int, isNumeric, asUInt);
        JSON_SER_DEFINE_CAST(long, isNumeric, asInt64, Json::Value::Int64);
        JSON_SER_DEFINE_CAST(unsigned long, isNumeric, asUInt64, Json::Value::UInt64);
        JSON_SER_DEFINE(float, isNumeric, asFloat);
        JSON_SER_DEFINE(double, isNumeric, asDouble);
	}
}  // namespace Json

#endif
