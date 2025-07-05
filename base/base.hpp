#pragma once

// C++版本必须在C++17以上
#if __cplusplus < 201703L
#error The C++ version is too low, at least it should be C++ 17
#endif

#include "base/type.hpp"
#include "base/ref.hpp"
#include "base/to_string.hpp"
#include "base/debug.hpp"
#include "base/exception.hpp"
#include "base/read_string.hpp"

#include "base/noncopyable_object.hpp"
#include "base/polymorphic_object.hpp"
#include "base/reference_object.hpp"
#include "base/rtti_object.hpp"
#include "base/printable_object.hpp"
