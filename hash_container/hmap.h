#pragma once
#include "cocos2d.h"

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
