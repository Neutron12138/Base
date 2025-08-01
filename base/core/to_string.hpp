#pragma once

#include <string>
#include <sstream>

namespace base
{
    //
    // 窄字符版本
    //

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
    /// @tparam ...Ts 参数类型列表
    /// @param ...args 参数
    /// @return 转换后的字符串
    template <typename... Ts>
    std::string to_string(Ts &&...args)
    {
        std::ostringstream oss;
        (oss << ... << std::forward<Ts>(args));
        return oss.str();
    }

    //
    // 宽字符版本
    //

    /// @brief 将一串参数转换成字符串
    /// @return 空字符串
    inline std::wstring to_wstring() { return {}; }

    // STL中的to_wstring()

    inline std::wstring to_wstring(int value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(long value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(long long value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(unsigned value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(unsigned long value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(unsigned long long value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(float value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(double value) { return std::to_wstring(value); }
    inline std::wstring to_wstring(long double value) { return std::to_wstring(value); }

    /// @brief 将一串参数转换成字符串
    /// @tparam ...Ts 参数类型列表
    /// @param ...args 参数
    /// @return 转换后的字符串
    template <typename... Ts>
    std::wstring to_wstring(Ts &&...args)
    {
        std::wostringstream oss;
        (oss << ... << std::forward<Ts>(args));
        return oss.str();
    }

} // namespace base
