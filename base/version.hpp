#pragma once

// 获取C++版本

#if __cplusplus >= 202302L
#define BASE_CPP_VERSION 23
#elif __cplusplus >= 202002L
#define BASE_CPP_VERSION 20
#elif __cplusplus >= 201703L
#define BASE_CPP_VERSION 17
#elif __cplusplus >= 201402L
#define BASE_CPP_VERSION 14
#elif __cplusplus >= 201103L
#define BASE_CPP_VERSION 11
#else
#define BASE_CPP_VERSION 0
#endif

// 检查C++版本

#if BASE_CPP_VERSION < 11
#error "The C++ version is too low, at least it should be C++ 11"
#elif BASE_CPP_VERSION < 17
#warning "The C++version is relatively low and some functions cannot be used"
#pragma message "Recommend using C++17"
#endif

// 是否支持某个C++版本

#if BASE_CPP_VERSION >= 11
#define BASE_CPP_VERSION_11 true
#else
#define BASE_CPP_VERSION_11 false
#endif

#if BASE_CPP_VERSION >= 14
#define BASE_CPP_VERSION_14 true
#else
#define BASE_CPP_VERSION_14 false
#endif

#if BASE_CPP_VERSION >= 17
#define BASE_CPP_VERSION_17 true
#else
#define BASE_CPP_VERSION_17 false
#endif

#if BASE_CPP_VERSION >= 20
#define BASE_CPP_VERSION_20 true
#else
#define BASE_CPP_VERSION_20 false
#endif

#if BASE_CPP_VERSION >= 23
#define BASE_CPP_VERSION_23 true
#else
#define BASE_CPP_VERSION_23 false
#endif
