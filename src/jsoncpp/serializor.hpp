#ifndef __JSONSER_TYPE_SERIALIZOR_H__
#define __JSONSER_TYPE_SERIALIZOR_H__

#include "def.hpp"
#include <string>
#include "hash_container/hmap.h"

using std::string;

#ifdef __GNUC__
#define __JSONSER_TEMPLATE template<>
#else
#define __JSONSER_TEMPLATE 
#endif // __GNUC__

#define JSONCPP_DEFINE(...) \
	inline Json::Value serialize() const \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).serialize(); \
	} \
	\
	inline bool deserialize(const Json::Value& j) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).deserialize(j); \
	}

#define JSONCPP_STATIC_DEFINE(...) \
	inline static Json::Value serialize() \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).serialize(); \
	} \
	\
	inline static bool deserialize(const Json::Value& j) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).deserialize(j); \
	}

#define JSONCPP_DEFINE_NEW_TYPE(TYPE, FACE, ...) \
	__JSONSER_TEMPLATE inline Json::Value serialize(const TYPE &FACE) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).serialize(); \
	} \
	\
	__JSONSER_TEMPLATE inline bool deserialize(const Json::Value& j, TYPE &FACE) \
	{ \
		return Json::type::make_serializor(__VA_ARGS__).deserialize(j); \
	}

#define JSONCPP_REGISTER_CUSTOM_CLASS_SER(TYPE) \
__JSONSER_TEMPLATE inline Json::Value Json::type::serialize(const TYPE &v) \
{ \
return v.serialize(); \
}

#define JSONCPP_REGISTER_CUSTOM_CLASS_DESER(TYPE) \
__JSONSER_TEMPLATE inline bool Json::type::deserialize(const Json::Value& j, TYPE &v) \
{ \
return v.deserialize(j); \
}

#define JSONCPP_REGISTER_CUSTOM_CLASS(TYPE) \
JSONCPP_REGISTER_CUSTOM_CLASS_SER(TYPE) \
JSONCPP_REGISTER_CUSTOM_CLASS_DESER(TYPE)

namespace Json {
	namespace type
	{

#ifdef __GNUC__
		template <typename V>
		inline bool deserialize(const Json::Value &j, typename std::map<std::string, V> &v);
		template <typename V>
		inline Json::Value serialize(typename std::map<std::string, V> const &v);

		template <typename K, typename V>
		inline bool deserialize(const Json::Value &j, typename std::map<K, V> &v);
		template <typename K, typename V>
        inline Json::Value serialize(typename std::map<K, V> const &v);
        
        template <typename V>
        inline bool deserialize(const Json::Value &j, hmap<std::string, V> &v);
        template <typename V>
        inline Json::Value serialize(hmap<std::string, V> const &v);
        
        template <typename K, typename V>
        inline bool deserialize(const Json::Value &j, hmap<K, V> &v);
        template <typename K, typename V>
        inline Json::Value serialize(hmap<K, V> const &v);
        
        template <typename K, typename V, typename H>
        inline bool deserialize(const Json::Value &j, hmap<K, V, H> &v);
        template <typename K, typename V, typename H>
        inline Json::Value serialize(hmap<K, V, H> const &v);

		template <typename V>
		inline bool deserialize(const Json::Value &j, typename std::vector<V> &v);
		template <typename V>
		inline Json::Value serialize( typename std::vector<V> const &v);

		template <typename V>
		inline bool deserialize(const Json::Value &j, V &v)
        {
            return false;
        }
		template <typename V>
		inline Json::Value serialize(const V &v)
        {
            return Json::Value::null;
        }
#endif

        template<typename A0 = void, typename A1 = void, typename A2 = void, typename A3 = void, typename A4 = void, typename A5 = void, typename A6 = void, typename A7 = void, typename A8 = void, typename A9 = void, typename A10 = void, typename A11 = void, typename A12 = void, typename A13 = void, typename A14 = void, typename A15 = void, typename A16 = void, typename A17 = void, typename A18 = void, typename A19 = void, typename A20 = void, typename A21 = void, typename A22 = void, typename A23 = void, typename A24 = void, typename A25 = void, typename A26 = void, typename A27 = void, typename A28 = void, typename A29 = void, typename A30 = void, typename A31 = void, typename A32 = void, typename A33 = void, typename A34 = void, typename A35 = void, typename A36 = void, typename A37 = void, typename A38 = void, typename A39 = void, typename A40 = void, typename A41 = void, typename A42 = void, typename A43 = void, typename A44 = void, typename A45 = void, typename A46 = void, typename A47 = void, typename A48 = void, typename A49 = void, typename A50 = void, typename A51 = void, typename A52 = void, typename A53 = void, typename A54 = void, typename A55 = void, typename A56 = void, typename A57 = void, typename A58 = void, typename A59 = void, typename A60 = void, typename A61 = void, typename A62 = void, typename A63 = void, typename A64 = void>
        struct serializor;

        template<typename A0>
        struct serializor<A0> {
            
            serializor(const char *_k0, A0 &_a0) :
            k0(_k0), a0(_a0) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
        };
        
        
        template<typename A0, typename A1>
        struct serializor<A0, A1> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
        };
        
        
        template<typename A0, typename A1, typename A2>
        struct serializor<A0, A1, A2> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3>
        struct serializor<A0, A1, A2, A3> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4>
        struct serializor<A0, A1, A2, A3, A4> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
        struct serializor<A0, A1, A2, A3, A4, A5> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
        struct serializor<A0, A1, A2, A3, A4, A5, A6> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57, const char *_k58, A58 &_a58) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57), k58(_k58), a58(_a58) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                ret = Json::type::deserialize(j[k58], a58) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                jVal[k58] = Json::type::serialize(a58);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
            const char *k58;
            A58 &a58;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57, const char *_k58, A58 &_a58, const char *_k59, A59 &_a59) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57), k58(_k58), a58(_a58), k59(_k59), a59(_a59) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                ret = Json::type::deserialize(j[k58], a58) && ret;
                ret = Json::type::deserialize(j[k59], a59) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                jVal[k58] = Json::type::serialize(a58);
                jVal[k59] = Json::type::serialize(a59);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
            const char *k58;
            A58 &a58;
            const char *k59;
            A59 &a59;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57, const char *_k58, A58 &_a58, const char *_k59, A59 &_a59, const char *_k60, A60 &_a60) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57), k58(_k58), a58(_a58), k59(_k59), a59(_a59), k60(_k60), a60(_a60) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                ret = Json::type::deserialize(j[k58], a58) && ret;
                ret = Json::type::deserialize(j[k59], a59) && ret;
                ret = Json::type::deserialize(j[k60], a60) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                jVal[k58] = Json::type::serialize(a58);
                jVal[k59] = Json::type::serialize(a59);
                jVal[k60] = Json::type::serialize(a60);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
            const char *k58;
            A58 &a58;
            const char *k59;
            A59 &a59;
            const char *k60;
            A60 &a60;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60, typename A61>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57, const char *_k58, A58 &_a58, const char *_k59, A59 &_a59, const char *_k60, A60 &_a60, const char *_k61, A61 &_a61) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57), k58(_k58), a58(_a58), k59(_k59), a59(_a59), k60(_k60), a60(_a60), k61(_k61), a61(_a61) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                ret = Json::type::deserialize(j[k58], a58) && ret;
                ret = Json::type::deserialize(j[k59], a59) && ret;
                ret = Json::type::deserialize(j[k60], a60) && ret;
                ret = Json::type::deserialize(j[k61], a61) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                jVal[k58] = Json::type::serialize(a58);
                jVal[k59] = Json::type::serialize(a59);
                jVal[k60] = Json::type::serialize(a60);
                jVal[k61] = Json::type::serialize(a61);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
            const char *k58;
            A58 &a58;
            const char *k59;
            A59 &a59;
            const char *k60;
            A60 &a60;
            const char *k61;
            A61 &a61;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60, typename A61, typename A62>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61, A62> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57, const char *_k58, A58 &_a58, const char *_k59, A59 &_a59, const char *_k60, A60 &_a60, const char *_k61, A61 &_a61, const char *_k62, A62 &_a62) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57), k58(_k58), a58(_a58), k59(_k59), a59(_a59), k60(_k60), a60(_a60), k61(_k61), a61(_a61), k62(_k62), a62(_a62) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                ret = Json::type::deserialize(j[k58], a58) && ret;
                ret = Json::type::deserialize(j[k59], a59) && ret;
                ret = Json::type::deserialize(j[k60], a60) && ret;
                ret = Json::type::deserialize(j[k61], a61) && ret;
                ret = Json::type::deserialize(j[k62], a62) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                jVal[k58] = Json::type::serialize(a58);
                jVal[k59] = Json::type::serialize(a59);
                jVal[k60] = Json::type::serialize(a60);
                jVal[k61] = Json::type::serialize(a61);
                jVal[k62] = Json::type::serialize(a62);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
            const char *k58;
            A58 &a58;
            const char *k59;
            A59 &a59;
            const char *k60;
            A60 &a60;
            const char *k61;
            A61 &a61;
            const char *k62;
            A62 &a62;
        };
        
        
        template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60, typename A61, typename A62, typename A63>
        struct serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61, A62, A63> {
            
            serializor(const char *_k0, A0 &_a0, const char *_k1, A1 &_a1, const char *_k2, A2 &_a2, const char *_k3, A3 &_a3, const char *_k4, A4 &_a4, const char *_k5, A5 &_a5, const char *_k6, A6 &_a6, const char *_k7, A7 &_a7, const char *_k8, A8 &_a8, const char *_k9, A9 &_a9, const char *_k10, A10 &_a10, const char *_k11, A11 &_a11, const char *_k12, A12 &_a12, const char *_k13, A13 &_a13, const char *_k14, A14 &_a14, const char *_k15, A15 &_a15, const char *_k16, A16 &_a16, const char *_k17, A17 &_a17, const char *_k18, A18 &_a18, const char *_k19, A19 &_a19, const char *_k20, A20 &_a20, const char *_k21, A21 &_a21, const char *_k22, A22 &_a22, const char *_k23, A23 &_a23, const char *_k24, A24 &_a24, const char *_k25, A25 &_a25, const char *_k26, A26 &_a26, const char *_k27, A27 &_a27, const char *_k28, A28 &_a28, const char *_k29, A29 &_a29, const char *_k30, A30 &_a30, const char *_k31, A31 &_a31, const char *_k32, A32 &_a32, const char *_k33, A33 &_a33, const char *_k34, A34 &_a34, const char *_k35, A35 &_a35, const char *_k36, A36 &_a36, const char *_k37, A37 &_a37, const char *_k38, A38 &_a38, const char *_k39, A39 &_a39, const char *_k40, A40 &_a40, const char *_k41, A41 &_a41, const char *_k42, A42 &_a42, const char *_k43, A43 &_a43, const char *_k44, A44 &_a44, const char *_k45, A45 &_a45, const char *_k46, A46 &_a46, const char *_k47, A47 &_a47, const char *_k48, A48 &_a48, const char *_k49, A49 &_a49, const char *_k50, A50 &_a50, const char *_k51, A51 &_a51, const char *_k52, A52 &_a52, const char *_k53, A53 &_a53, const char *_k54, A54 &_a54, const char *_k55, A55 &_a55, const char *_k56, A56 &_a56, const char *_k57, A57 &_a57, const char *_k58, A58 &_a58, const char *_k59, A59 &_a59, const char *_k60, A60 &_a60, const char *_k61, A61 &_a61, const char *_k62, A62 &_a62, const char *_k63, A63 &_a63) :
            k0(_k0), a0(_a0), k1(_k1), a1(_a1), k2(_k2), a2(_a2), k3(_k3), a3(_a3), k4(_k4), a4(_a4), k5(_k5), a5(_a5), k6(_k6), a6(_a6), k7(_k7), a7(_a7), k8(_k8), a8(_a8), k9(_k9), a9(_a9), k10(_k10), a10(_a10), k11(_k11), a11(_a11), k12(_k12), a12(_a12), k13(_k13), a13(_a13), k14(_k14), a14(_a14), k15(_k15), a15(_a15), k16(_k16), a16(_a16), k17(_k17), a17(_a17), k18(_k18), a18(_a18), k19(_k19), a19(_a19), k20(_k20), a20(_a20), k21(_k21), a21(_a21), k22(_k22), a22(_a22), k23(_k23), a23(_a23), k24(_k24), a24(_a24), k25(_k25), a25(_a25), k26(_k26), a26(_a26), k27(_k27), a27(_a27), k28(_k28), a28(_a28), k29(_k29), a29(_a29), k30(_k30), a30(_a30), k31(_k31), a31(_a31), k32(_k32), a32(_a32), k33(_k33), a33(_a33), k34(_k34), a34(_a34), k35(_k35), a35(_a35), k36(_k36), a36(_a36), k37(_k37), a37(_a37), k38(_k38), a38(_a38), k39(_k39), a39(_a39), k40(_k40), a40(_a40), k41(_k41), a41(_a41), k42(_k42), a42(_a42), k43(_k43), a43(_a43), k44(_k44), a44(_a44), k45(_k45), a45(_a45), k46(_k46), a46(_a46), k47(_k47), a47(_a47), k48(_k48), a48(_a48), k49(_k49), a49(_a49), k50(_k50), a50(_a50), k51(_k51), a51(_a51), k52(_k52), a52(_a52), k53(_k53), a53(_a53), k54(_k54), a54(_a54), k55(_k55), a55(_a55), k56(_k56), a56(_a56), k57(_k57), a57(_a57), k58(_k58), a58(_a58), k59(_k59), a59(_a59), k60(_k60), a60(_a60), k61(_k61), a61(_a61), k62(_k62), a62(_a62), k63(_k63), a63(_a63) {
            }
            
            bool deserialize(const Json::Value &j) {
                bool ret = true;
                ret = Json::type::deserialize(j[k0], a0) && ret;
                ret = Json::type::deserialize(j[k1], a1) && ret;
                ret = Json::type::deserialize(j[k2], a2) && ret;
                ret = Json::type::deserialize(j[k3], a3) && ret;
                ret = Json::type::deserialize(j[k4], a4) && ret;
                ret = Json::type::deserialize(j[k5], a5) && ret;
                ret = Json::type::deserialize(j[k6], a6) && ret;
                ret = Json::type::deserialize(j[k7], a7) && ret;
                ret = Json::type::deserialize(j[k8], a8) && ret;
                ret = Json::type::deserialize(j[k9], a9) && ret;
                ret = Json::type::deserialize(j[k10], a10) && ret;
                ret = Json::type::deserialize(j[k11], a11) && ret;
                ret = Json::type::deserialize(j[k12], a12) && ret;
                ret = Json::type::deserialize(j[k13], a13) && ret;
                ret = Json::type::deserialize(j[k14], a14) && ret;
                ret = Json::type::deserialize(j[k15], a15) && ret;
                ret = Json::type::deserialize(j[k16], a16) && ret;
                ret = Json::type::deserialize(j[k17], a17) && ret;
                ret = Json::type::deserialize(j[k18], a18) && ret;
                ret = Json::type::deserialize(j[k19], a19) && ret;
                ret = Json::type::deserialize(j[k20], a20) && ret;
                ret = Json::type::deserialize(j[k21], a21) && ret;
                ret = Json::type::deserialize(j[k22], a22) && ret;
                ret = Json::type::deserialize(j[k23], a23) && ret;
                ret = Json::type::deserialize(j[k24], a24) && ret;
                ret = Json::type::deserialize(j[k25], a25) && ret;
                ret = Json::type::deserialize(j[k26], a26) && ret;
                ret = Json::type::deserialize(j[k27], a27) && ret;
                ret = Json::type::deserialize(j[k28], a28) && ret;
                ret = Json::type::deserialize(j[k29], a29) && ret;
                ret = Json::type::deserialize(j[k30], a30) && ret;
                ret = Json::type::deserialize(j[k31], a31) && ret;
                ret = Json::type::deserialize(j[k32], a32) && ret;
                ret = Json::type::deserialize(j[k33], a33) && ret;
                ret = Json::type::deserialize(j[k34], a34) && ret;
                ret = Json::type::deserialize(j[k35], a35) && ret;
                ret = Json::type::deserialize(j[k36], a36) && ret;
                ret = Json::type::deserialize(j[k37], a37) && ret;
                ret = Json::type::deserialize(j[k38], a38) && ret;
                ret = Json::type::deserialize(j[k39], a39) && ret;
                ret = Json::type::deserialize(j[k40], a40) && ret;
                ret = Json::type::deserialize(j[k41], a41) && ret;
                ret = Json::type::deserialize(j[k42], a42) && ret;
                ret = Json::type::deserialize(j[k43], a43) && ret;
                ret = Json::type::deserialize(j[k44], a44) && ret;
                ret = Json::type::deserialize(j[k45], a45) && ret;
                ret = Json::type::deserialize(j[k46], a46) && ret;
                ret = Json::type::deserialize(j[k47], a47) && ret;
                ret = Json::type::deserialize(j[k48], a48) && ret;
                ret = Json::type::deserialize(j[k49], a49) && ret;
                ret = Json::type::deserialize(j[k50], a50) && ret;
                ret = Json::type::deserialize(j[k51], a51) && ret;
                ret = Json::type::deserialize(j[k52], a52) && ret;
                ret = Json::type::deserialize(j[k53], a53) && ret;
                ret = Json::type::deserialize(j[k54], a54) && ret;
                ret = Json::type::deserialize(j[k55], a55) && ret;
                ret = Json::type::deserialize(j[k56], a56) && ret;
                ret = Json::type::deserialize(j[k57], a57) && ret;
                ret = Json::type::deserialize(j[k58], a58) && ret;
                ret = Json::type::deserialize(j[k59], a59) && ret;
                ret = Json::type::deserialize(j[k60], a60) && ret;
                ret = Json::type::deserialize(j[k61], a61) && ret;
                ret = Json::type::deserialize(j[k62], a62) && ret;
                ret = Json::type::deserialize(j[k63], a63) && ret;
                return true;
            }
            
            Json::Value serialize() const {
                Json::Value jVal;
                jVal[k0] = Json::type::serialize(a0);
                jVal[k1] = Json::type::serialize(a1);
                jVal[k2] = Json::type::serialize(a2);
                jVal[k3] = Json::type::serialize(a3);
                jVal[k4] = Json::type::serialize(a4);
                jVal[k5] = Json::type::serialize(a5);
                jVal[k6] = Json::type::serialize(a6);
                jVal[k7] = Json::type::serialize(a7);
                jVal[k8] = Json::type::serialize(a8);
                jVal[k9] = Json::type::serialize(a9);
                jVal[k10] = Json::type::serialize(a10);
                jVal[k11] = Json::type::serialize(a11);
                jVal[k12] = Json::type::serialize(a12);
                jVal[k13] = Json::type::serialize(a13);
                jVal[k14] = Json::type::serialize(a14);
                jVal[k15] = Json::type::serialize(a15);
                jVal[k16] = Json::type::serialize(a16);
                jVal[k17] = Json::type::serialize(a17);
                jVal[k18] = Json::type::serialize(a18);
                jVal[k19] = Json::type::serialize(a19);
                jVal[k20] = Json::type::serialize(a20);
                jVal[k21] = Json::type::serialize(a21);
                jVal[k22] = Json::type::serialize(a22);
                jVal[k23] = Json::type::serialize(a23);
                jVal[k24] = Json::type::serialize(a24);
                jVal[k25] = Json::type::serialize(a25);
                jVal[k26] = Json::type::serialize(a26);
                jVal[k27] = Json::type::serialize(a27);
                jVal[k28] = Json::type::serialize(a28);
                jVal[k29] = Json::type::serialize(a29);
                jVal[k30] = Json::type::serialize(a30);
                jVal[k31] = Json::type::serialize(a31);
                jVal[k32] = Json::type::serialize(a32);
                jVal[k33] = Json::type::serialize(a33);
                jVal[k34] = Json::type::serialize(a34);
                jVal[k35] = Json::type::serialize(a35);
                jVal[k36] = Json::type::serialize(a36);
                jVal[k37] = Json::type::serialize(a37);
                jVal[k38] = Json::type::serialize(a38);
                jVal[k39] = Json::type::serialize(a39);
                jVal[k40] = Json::type::serialize(a40);
                jVal[k41] = Json::type::serialize(a41);
                jVal[k42] = Json::type::serialize(a42);
                jVal[k43] = Json::type::serialize(a43);
                jVal[k44] = Json::type::serialize(a44);
                jVal[k45] = Json::type::serialize(a45);
                jVal[k46] = Json::type::serialize(a46);
                jVal[k47] = Json::type::serialize(a47);
                jVal[k48] = Json::type::serialize(a48);
                jVal[k49] = Json::type::serialize(a49);
                jVal[k50] = Json::type::serialize(a50);
                jVal[k51] = Json::type::serialize(a51);
                jVal[k52] = Json::type::serialize(a52);
                jVal[k53] = Json::type::serialize(a53);
                jVal[k54] = Json::type::serialize(a54);
                jVal[k55] = Json::type::serialize(a55);
                jVal[k56] = Json::type::serialize(a56);
                jVal[k57] = Json::type::serialize(a57);
                jVal[k58] = Json::type::serialize(a58);
                jVal[k59] = Json::type::serialize(a59);
                jVal[k60] = Json::type::serialize(a60);
                jVal[k61] = Json::type::serialize(a61);
                jVal[k62] = Json::type::serialize(a62);
                jVal[k63] = Json::type::serialize(a63);
                return jVal;
            }
            
            const char *k0;
            A0 &a0;
            const char *k1;
            A1 &a1;
            const char *k2;
            A2 &a2;
            const char *k3;
            A3 &a3;
            const char *k4;
            A4 &a4;
            const char *k5;
            A5 &a5;
            const char *k6;
            A6 &a6;
            const char *k7;
            A7 &a7;
            const char *k8;
            A8 &a8;
            const char *k9;
            A9 &a9;
            const char *k10;
            A10 &a10;
            const char *k11;
            A11 &a11;
            const char *k12;
            A12 &a12;
            const char *k13;
            A13 &a13;
            const char *k14;
            A14 &a14;
            const char *k15;
            A15 &a15;
            const char *k16;
            A16 &a16;
            const char *k17;
            A17 &a17;
            const char *k18;
            A18 &a18;
            const char *k19;
            A19 &a19;
            const char *k20;
            A20 &a20;
            const char *k21;
            A21 &a21;
            const char *k22;
            A22 &a22;
            const char *k23;
            A23 &a23;
            const char *k24;
            A24 &a24;
            const char *k25;
            A25 &a25;
            const char *k26;
            A26 &a26;
            const char *k27;
            A27 &a27;
            const char *k28;
            A28 &a28;
            const char *k29;
            A29 &a29;
            const char *k30;
            A30 &a30;
            const char *k31;
            A31 &a31;
            const char *k32;
            A32 &a32;
            const char *k33;
            A33 &a33;
            const char *k34;
            A34 &a34;
            const char *k35;
            A35 &a35;
            const char *k36;
            A36 &a36;
            const char *k37;
            A37 &a37;
            const char *k38;
            A38 &a38;
            const char *k39;
            A39 &a39;
            const char *k40;
            A40 &a40;
            const char *k41;
            A41 &a41;
            const char *k42;
            A42 &a42;
            const char *k43;
            A43 &a43;
            const char *k44;
            A44 &a44;
            const char *k45;
            A45 &a45;
            const char *k46;
            A46 &a46;
            const char *k47;
            A47 &a47;
            const char *k48;
            A48 &a48;
            const char *k49;
            A49 &a49;
            const char *k50;
            A50 &a50;
            const char *k51;
            A51 &a51;
            const char *k52;
            A52 &a52;
            const char *k53;
            A53 &a53;
            const char *k54;
            A54 &a54;
            const char *k55;
            A55 &a55;
            const char *k56;
            A56 &a56;
            const char *k57;
            A57 &a57;
            const char *k58;
            A58 &a58;
            const char *k59;
            A59 &a59;
            const char *k60;
            A60 &a60;
            const char *k61;
            A61 &a61;
            const char *k62;
            A62 &a62;
            const char *k63;
            A63 &a63;
        };

        template <typename A0>
        serializor<A0> make_serializor(const char *k0, A0 &a0) {
            return serializor<A0>(k0, a0);
        }
        
        template <typename A0, typename A1>
        serializor<A0, A1> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1) {
            return serializor<A0, A1>(k0, a0, k1, a1);
        }
        
        template <typename A0, typename A1, typename A2>
        serializor<A0, A1, A2> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2) {
            return serializor<A0, A1, A2>(k0, a0, k1, a1, k2, a2);
        }
        
        template <typename A0, typename A1, typename A2, typename A3>
        serializor<A0, A1, A2, A3> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3) {
            return serializor<A0, A1, A2, A3>(k0, a0, k1, a1, k2, a2, k3, a3);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4>
        serializor<A0, A1, A2, A3, A4> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4) {
            return serializor<A0, A1, A2, A3, A4>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
        serializor<A0, A1, A2, A3, A4, A5> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5) {
            return serializor<A0, A1, A2, A3, A4, A5>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
        serializor<A0, A1, A2, A3, A4, A5, A6> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6) {
            return serializor<A0, A1, A2, A3, A4, A5, A6>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57, const char *k58, A58 &a58) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57, k58, a58);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57, const char *k58, A58 &a58, const char *k59, A59 &a59) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57, k58, a58, k59, a59);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57, const char *k58, A58 &a58, const char *k59, A59 &a59, const char *k60, A60 &a60) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57, k58, a58, k59, a59, k60, a60);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60, typename A61>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57, const char *k58, A58 &a58, const char *k59, A59 &a59, const char *k60, A60 &a60, const char *k61, A61 &a61) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57, k58, a58, k59, a59, k60, a60, k61, a61);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60, typename A61, typename A62>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61, A62> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57, const char *k58, A58 &a58, const char *k59, A59 &a59, const char *k60, A60 &a60, const char *k61, A61 &a61, const char *k62, A62 &a62) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61, A62>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57, k58, a58, k59, a59, k60, a60, k61, a61, k62, a62);
        }
        
        template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47, typename A48, typename A49, typename A50, typename A51, typename A52, typename A53, typename A54, typename A55, typename A56, typename A57, typename A58, typename A59, typename A60, typename A61, typename A62, typename A63>
        serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61, A62, A63> make_serializor(const char *k0, A0 &a0, const char *k1, A1 &a1, const char *k2, A2 &a2, const char *k3, A3 &a3, const char *k4, A4 &a4, const char *k5, A5 &a5, const char *k6, A6 &a6, const char *k7, A7 &a7, const char *k8, A8 &a8, const char *k9, A9 &a9, const char *k10, A10 &a10, const char *k11, A11 &a11, const char *k12, A12 &a12, const char *k13, A13 &a13, const char *k14, A14 &a14, const char *k15, A15 &a15, const char *k16, A16 &a16, const char *k17, A17 &a17, const char *k18, A18 &a18, const char *k19, A19 &a19, const char *k20, A20 &a20, const char *k21, A21 &a21, const char *k22, A22 &a22, const char *k23, A23 &a23, const char *k24, A24 &a24, const char *k25, A25 &a25, const char *k26, A26 &a26, const char *k27, A27 &a27, const char *k28, A28 &a28, const char *k29, A29 &a29, const char *k30, A30 &a30, const char *k31, A31 &a31, const char *k32, A32 &a32, const char *k33, A33 &a33, const char *k34, A34 &a34, const char *k35, A35 &a35, const char *k36, A36 &a36, const char *k37, A37 &a37, const char *k38, A38 &a38, const char *k39, A39 &a39, const char *k40, A40 &a40, const char *k41, A41 &a41, const char *k42, A42 &a42, const char *k43, A43 &a43, const char *k44, A44 &a44, const char *k45, A45 &a45, const char *k46, A46 &a46, const char *k47, A47 &a47, const char *k48, A48 &a48, const char *k49, A49 &a49, const char *k50, A50 &a50, const char *k51, A51 &a51, const char *k52, A52 &a52, const char *k53, A53 &a53, const char *k54, A54 &a54, const char *k55, A55 &a55, const char *k56, A56 &a56, const char *k57, A57 &a57, const char *k58, A58 &a58, const char *k59, A59 &a59, const char *k60, A60 &a60, const char *k61, A61 &a61, const char *k62, A62 &a62, const char *k63, A63 &a63) {
            return serializor<A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, A41, A42, A43, A44, A45, A46, A47, A48, A49, A50, A51, A52, A53, A54, A55, A56, A57, A58, A59, A60, A61, A62, A63>(k0, a0, k1, a1, k2, a2, k3, a3, k4, a4, k5, a5, k6, a6, k7, a7, k8, a8, k9, a9, k10, a10, k11, a11, k12, a12, k13, a13, k14, a14, k15, a15, k16, a16, k17, a17, k18, a18, k19, a19, k20, a20, k21, a21, k22, a22, k23, a23, k24, a24, k25, a25, k26, a26, k27, a27, k28, a28, k29, a29, k30, a30, k31, a31, k32, a32, k33, a33, k34, a34, k35, a35, k36, a36, k37, a37, k38, a38, k39, a39, k40, a40, k41, a41, k42, a42, k43, a43, k44, a44, k45, a45, k46, a46, k47, a47, k48, a48, k49, a49, k50, a50, k51, a51, k52, a52, k53, a53, k54, a54, k55, a55, k56, a56, k57, a57, k58, a58, k59, a59, k60, a60, k61, a61, k62, a62, k63, a63); 
        }
	}	// namespace type
}  // namespace Json

#endif
