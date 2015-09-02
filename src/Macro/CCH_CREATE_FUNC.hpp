#ifndef CCH_CREATE_FUNC_HPP
#define CCH_CREATE_FUNC_HPP
#include "LAST_ARG.hpp"
#include "CUT_LAST_ARG.hpp"
#include "CCH_FOR.hpp"

#define BUILD_PAR(TYPE, _D, i) TYPE arg_##i,
#define BUILD_ARG(TYPE, _D, i) arg_##i,

#define CCH_CREATE_FUNC(CLASS, ...)\
static inline CLASS* create(CCH_FOR(BUILD_PAR, _, CCH_CUT_LAST_ARG(__VA_ARGS__)) CCH_LAST_ARG(__VA_ARGS__) arg_last) \
{ \
    return Utils::createx<CLASS>(new CLASS, [=](CLASS *c) \
    { \
        return c->init(CCH_FOR(BUILD_ARG, _, CCH_EXPAND(CCH_CUT_LAST_ARG(__VA_ARGS__))) arg_last); \
    }); \
}


#endif /* CCH_CREATE_FUNC_HPP */