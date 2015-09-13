//
//  PAIR.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/5/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#ifndef ccHelp_ios_mac_PAIR_h
#define ccHelp_ios_mac_PAIR_h
#include "CCH_FOR.hpp"

#define REM(...) __VA_ARGS__
#define EAT(...)

// Retrieve the type
#define TYPEOF(x) DETAIL_TYPEOF(DETAIL_TYPEOF_PROBE x,)
#define DETAIL_TYPEOF(...) DETAIL_TYPEOF_HEAD(__VA_ARGS__)
#define DETAIL_TYPEOF_HEAD(x, ...) REM x
#define DETAIL_TYPEOF_PROBE(...) (__VA_ARGS__),

#define STRIP(x) EAT x
#define PAIR(x) REM x

#define P_HEAD TYPEOF
#define P_TAIL STRIP
#define CCH_STRINGIZE(x) CCH_STRINGIZE_I(x)
#define CCH_STRINGIZE_I(x) #x

#define ENUM_UTILS_DECL(NS, NAME) \
template<> \
string Json::type::strSerialize<NS::NAME>(const NS::NAME &e); \
template<> \
bool Json::type::strDeserialize<NS::NAME>(const string &s, NS::NAME &e);

#define ENUM_UTILS_IMPL(NS, NAME, ...) \
\
template<> \
string Json::type::strSerialize<NS::NAME>(const NS::NAME &e) \
{ \
    switch (e) \
    { \
        CCH_FOR(TO_STRING_CASE, NS, __VA_ARGS__) \
    } \
    \
    return "";\
} \
template<> \
bool Json::type::strDeserialize<NS::NAME>(const string &s, NS::NAME &e) \
{ \
    CCH_FOR(FROM_STRING_IF, NS, __VA_ARGS__) \
    return false; \
} \
template<> \
NS::NAME ccHelp::ENUM_ALL<NS::NAME>::VALUES[] = {CCH_FOR(ALL_VALUES_EACH, NS, __VA_ARGS__)}; \
template<> \
uint ccHelp::ENUM_ALL<NS::NAME>::N = PP_NARG(__VA_ARGS__);

#define TO_STRING_CASE(x, NS, i) \
case NS::x: \
    return #x;

#define FROM_STRING_IF(x, NS, i) \
if (!strcmp(#x, s.c_str())) \
{ \
    e = NS::x; \
    return true; \
}

#define ALL_VALUES_EACH(x, NS, i) NS::x,

#endif
