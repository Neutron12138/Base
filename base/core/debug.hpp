#pragma once

#include "to_string.hpp"

#define BASE_DEBUG_ARGS __FILE__, __FUNCTION__, __LINE__
#define BASE_DEBUG_INFO ::base::str_debug_info(BASE_DEBUG_ARGS)
#define BASE_CLASS_DEBUG_INFO ::base::str_debug_info(this, BASE_DEBUG_ARGS)

namespace base
{
    /// @brief 将调试信息转化为字符串
    /// @param file 文件名
    /// @param function 函数名
    /// @param line 行号
    /// @return 转化后的字符串
    inline std::string str_debug_info(std::string_view file, std::string_view function, int line)
    {
        return to_string(
            "in file: \"", file,
            "\", function: \"", function,
            "\", line: ", line);
    }

    /// @brief 将调试信息转化为字符串
    /// @param object 对象地址
    /// @param file 文件名
    /// @param function 函数名
    /// @param line 行号
    /// @return 转化后的字符串
    inline std::string str_debug_info(const void *object,
                                      std::string_view file, std::string_view function, int line)
    {
        return to_string(
            "(object@", object,
            ") in file: \"", file,
            "\", function: \"", function,
            "\", line: ", line);
    }

} // namespace base
