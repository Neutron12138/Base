#pragma once

#include <string>
#include <sstream>
#include <string_view>

namespace base
{
    /// @brief 将一串参数转换成字符串
    /// @return 空字符串
    inline std::string to_string() { return {}; }

    // STL中的to_string()

    inline std::string to_string(int value) { return std::to_string(value); }
    inline std::string to_string(long value) { return std::to_string(value); }
    inline std::string to_string(long long value) { return std::to_string(value); }
    inline std::string to_string(unsigned value) { return std::to_string(value); }
    inline std::string to_string(unsigned long value) { return std::to_string(value); }
    inline std::string to_string(unsigned long long value) { return std::to_string(value); }
    inline std::string to_string(float value) { return std::to_string(value); }
    inline std::string to_string(double value) { return std::to_string(value); }
    inline std::string to_string(long double value) { return std::to_string(value); }

    /// @brief 将一串参数转换成字符串
    /// @tparam ...Ts 参数类型
    /// @param ...args 参数
    /// @return 转换后的字符串
    template <typename... Ts>
    std::string to_string(Ts &&...args)
    {
        std::ostringstream oss;
        (oss << ... << std::forward<Ts>(args));
        return oss.str();
    }

} // namespace base
