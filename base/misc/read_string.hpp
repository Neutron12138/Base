#pragma once

#include <fstream>
#include "../core/exception.hpp"

namespace base
{
    /// @brief 以文本方式从输入流中读取全部内容
    /// @param is 输入流
    /// @return 内容字符串
    std::string read_string_from_istream(std::istream &is)
    {
        if (!is)
            throw BASE_MAKE_RUNTIME_ERROR("Invalid input stream");

        return std::string(
            std::istreambuf_iterator<char>(is),
            std::istreambuf_iterator<char>());
    }

    /// @brief 以文本方式从文件中读取全部内容
    /// @param filename 文件名
    /// @return 内容字符串
    std::string read_string_from_file(const std::string &filename)
    {
        std::ifstream fin;
        fin.open(filename);
        if (!fin)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to open file: \"", filename, "\"");

        return std::string(
            std::istreambuf_iterator<char>(fin),
            std::istreambuf_iterator<char>());
    }

} // namespace base
