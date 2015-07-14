#ifndef __JSONSER_TYPE_BOOL_H__
#define __JSONSER_TYPE_BOOL_H__

#include "def.hpp"

namespace Json {
	namespace type
	{
#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__
		__JSONSER_TEMPLATE inline bool deserialize(const Value &j, bool &v)
		{
			if (j.isBool())
			{
				v = j.asBool();
				return true;
			}
            else if (j.isNumeric())
            {
                v = (j.asInt() != 0);
            }
            else if (j.isString())
            {
                std::string s = j.asString();
                for (char &c : s) {c = tolower(c);}
                s.erase(0, s.find_first_not_of(" \t"));       //prefixing spaces
                s.erase(s.find_last_not_of(" \t") + 1);
                
                if ("true" == s || "yes" == s)
                {
                    v = true;
                    return true;
                }
                
                if ("false" == s || "no" == s || "" == s)
                {
                    v = false;
                    return true;
                }
            }

			return false;
		}

		__JSONSER_TEMPLATE inline Value serialize(const bool &v)
		{
			return Json::Value(v);
		}
	}
}  // namespace Json

#endif
