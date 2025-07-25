#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../core/type.hpp"
#include "../core/exception.hpp"

namespace base
{
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

    /// @brief 以二进制方式从文件读取全部内容
    /// @param filename 文件名
    /// @return 缓冲区
    std::vector<Byte> read_bytes_from_file(const std::string &filename)
    {
        std::ifstream fin;
        fin.open(filename, std::ios::binary);
        if (!fin)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to open file: \"", filename, "\"");

        fin.seekg(0, std::ios::end);
        std::streamsize size = fin.tellg();
        if (size <= 0)
            throw BASE_MAKE_RUNTIME_ERROR("Invalid input stream size");

        std::vector<Byte> buffer(size);
        fin.seekg(std::ios::beg);
        if (!fin.read(reinterpret_cast<char *>(buffer.data()), size))
            throw BASE_MAKE_RUNTIME_ERROR("Failed to read from input stream");

        return buffer;
    }

} // namespace base
