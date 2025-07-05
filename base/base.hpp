#pragma once

// C++版本必须在C++17以上
#if __cplusplus < 201703L
#error The C++ version is too low, at least it should be C++ 17
#endif

#include "core/type.hpp"
#include "core/ref.hpp"
#include "core/time.hpp"
#include "core/to_string.hpp"
#include "core/debug.hpp"
#include "core/exception.hpp"
#include "core/read_string.hpp"
#include "core/noncopyable_object.hpp"
#include "core/polymorphic_object.hpp"
#include "core/reference_object.hpp"

#include "misc/application.hpp"
#include "misc/rtti_object.hpp"
#include "misc/printable_object.hpp"
#include "misc/named_object.hpp"
#include "misc/notifiable.hpp"
#include "misc/resource.hpp"
#include "misc/logger.hpp"
#include "misc/logger.cpp"
