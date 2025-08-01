#pragma once

#include <cstdint>

namespace base
{
    /// @brief 8位有符号整数
    using Int8 = std::int8_t;
    /// @brief 19位有符号整数
    using Int16 = std::int16_t;
    /// @brief 32位有符号整数
    using Int32 = std::int32_t;
    /// @brief 64位有符号整数
    using Int64 = std::int64_t;

    /// @brief 8位无符号整数
    using UInt8 = std::uint8_t;
    /// @brief 16位无符号整数
    using UInt16 = std::uint16_t;
    /// @brief 32位无符号整数
    using UInt32 = std::uint32_t;
    /// @brief 64位无符号整数
    using UInt64 = std::uint64_t;

    /// @brief 布尔类型
    using Bool = bool;
    /// @brief 字节类型
    using Byte = UInt8;
    /// @brief 大小类型
    using Size = std::size_t;
    /// @brief 整数指针类型
    using IntPtr = std::intptr_t;
    /// @brief 无符号整数指针类型
    using UIntPtr = std::uintptr_t;

    /// @brief 32位浮点数
    using Float32 = float;
    /// @brief 64位浮点数
    using Float64 = double;

#ifdef __SIZEOF_LONG_DOUBLE__
#if __SIZEOF_LONG_DOUBLE__ == 16
#define BASE_TYPE_HAS_FLOAT_128
    /// @brief 128位浮点数
    using Float128 = long double;
#endif
#endif

#ifdef BASE_REQUIRE_FLOAT_128
#ifndef BASE_TYPE_HAS_FLOAT_128
#error "Require 128 bits float"
#endif
#endif

} // namespace base
