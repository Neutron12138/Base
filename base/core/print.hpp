#pragma once

#include <iostream>
#include <bits/move.h>

namespace base
{
    /// @brief 打印一串内容到输出流，什么都不会输出
    inline void print_to(std::ostream &) {}

    /// @brief 打印一串内容到输出流，但只会换行
    /// @param os 输出流
    inline void print_line_to(std::ostream &os) { os << '\n'; }

    /// @brief 打印一串内容到输出流
    /// @tparam ...Ts 参数类型列表
    /// @param os 输出流
    /// @param ...args 参数
    template <typename... Ts>
    inline void print_to(std::ostream &os, Ts &&...args) { (os << ... << args); }

    /// @brief 打印一串内容到输出流，并自动换行
    /// @tparam ...Ts 参数类型列表
    /// @param os 输出流
    /// @param ...args 参数
    template <typename... Ts>
    inline void print_line_to(std::ostream &os, Ts &&...args) { (os << ... << args) << '\n'; }

    // 打印到标准输出流

    template <typename... Ts>
    inline void print(Ts &&...args) { print_to(std::cout, std::forward<Ts>(args)...); }

    template <typename... Ts>
    inline void print_line(Ts &&...args) { print_line_to(std::cout, std::forward<Ts>(args)...); }

    template <typename... Ts>
    inline void print_error(Ts &&...args) { print_to(std::cerr, std::forward<Ts>(args)...); }

    template <typename... Ts>
    inline void print_error_line(Ts &&...args) { print_line_to(std::cerr, std::forward<Ts>(args)...); }

    template <typename... Ts>
    inline void print_log(Ts &&...args) { print_to(std::clog, std::forward<Ts>(args)...); }

    template <typename... Ts>
    inline void print_log_line(Ts &&...args) { print_line_to(std::clog, std::forward<Ts>(args)...); }

} // namespace base
