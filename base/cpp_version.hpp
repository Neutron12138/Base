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

#if BASE_CPP_VERSION < 17
#warning "The C++ version is too low"
#endif

#ifdef BASE_REQUIRE_CPP_20
#if BASE_CPP_VERSION < 20
#error "Require C++ 20"
#endif
#endif

#ifdef BASE_REQUIRE_CPP_23
#if BASE_CPP_VERSION < 23
#error "Require C++ 23"
#endif
#endif

// 是否支持某个C++版本

#if BASE_CPP_VERSION >= 11
#define BASE_SUPPORT_CPP_11 true
#else
#define BASE_SUPPORT_CPP_11 false
#endif

#if BASE_CPP_VERSION >= 14
#define BASE_SUPPORT_CPP_14 true
#else
#define BASE_SUPPORT_CPP_14 false
#endif

#if BASE_CPP_VERSION >= 17
#define BASE_SUPPORT_CPP_17 true
#else
#define BASE_SUPPORT_CPP_17 false
#endif

#if BASE_CPP_VERSION >= 20
#define BASE_SUPPORT_CPP_20 true
#else
#define BASE_SUPPORT_CPP_20 false
#endif

#if BASE_CPP_VERSION >= 23
#define BASE_SUPPORT_CPP_23 true
#else
#define BASE_SUPPORT_CPP_23 false
#endif
