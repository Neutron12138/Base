#pragma once

#include <fstream>
#include <vector>
#include "../core/type.hpp"
#include "../core/exception.hpp"

namespace base
{
    /// @brief 以二进制方式从输入流读取全部内容
    /// @param is 输入流
    /// @return 缓冲区
    std::vector<Byte> read_bytes_from_stream(std::istream &is)
    {
        if (!is)
            throw BASE_MAKE_RUNTIME_ERROR("Invalid input stream");

        is.seekg(0, std::ios::end);
        std::streamsize size = is.tellg();
        if (size <= 0)
            throw BASE_MAKE_RUNTIME_ERROR("Invalid input stream size");
        is.seekg(std::ios::beg);

        std::vector<Byte> buffer(size);
        if (!is.read(reinterpret_cast<char *>(buffer.data()), size))
            throw BASE_MAKE_RUNTIME_ERROR("Failed to read from input stream");

        return buffer;
    }

    /// @brief 以二进制方式从文件读取全部内容
    /// @param filename 文件名
    /// @return 缓冲区
    std::vector<Byte> read_bytes_from_file(const std::string &filename)
    {
        std::ifstream fin;
        fin.open(filename, std::ios::binary);
        if (fin.bad())
            throw BASE_MAKE_RUNTIME_ERROR("Failed to open file: \"", filename, "\"");

        return read_bytes_from_stream(fin);
    }

} // namespace base
