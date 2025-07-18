#pragma once

#include <stdexcept>
#include "debug.hpp"

#define BASE_MAKE_RUNTIME_ERROR(...) \
    ::base::make_runtime_error(BASE_DEBUG_INFO, __VA_ARGS__)

namespace base
{
    template <typename... Ts>
    inline std::string format_exception_message(const std::string &debug_info, Ts... args)
    {
        return to_string("[", debug_info, "]\n", args...);
    }

    template <typename... Ts>
    inline std::runtime_error make_runtime_error(const std::string &debug_info, Ts... args)
    {
        return std::runtime_error(format_exception_message(debug_info, args...));
    }

} // namespace base
