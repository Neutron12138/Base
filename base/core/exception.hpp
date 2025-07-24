#pragma once

#include <stdexcept>
#include "debug.hpp"

#define BASE_EXCEPTION_MAKE_ERROR_FUNCTION(error)                                                              \
    template <typename... Ts>                                                                                  \
    inline std::error make_##error(const std::string &debug_info, Ts &&...args)                                \
    {                                                                                                          \
        return std::error(format_exception_message(debug_info, "(", #error, ") ", std::forward<Ts>(args)...)); \
    }

#define BASE_MAKE_LOGIC_ERROR(...) ::base::make_logic_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_INVALID_ARGUMENT_ERROR(...) ::base::make_invalid_argument_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_DOMAIN_ERROR(...) ::base::make_domain_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_LENGTH_ERROR(...) ::base::make_length_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_OUT_OF_RANGE_ERROR(...) ::base::make_out_of_range_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_RUNTIME_ERROR(...) ::base::make_runtime_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_RANGE_ERROR(...) ::base::make_range_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_OVERFLOW_ERROR(...) ::base::make_overflow_error(BASE_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_UNDERFLOW_ERROR(...) ::base::make_underflow_error(BASE_DEBUG_INFO, __VA_ARGS__)

#define BASE_MAKE_CLASS_LOGIC_ERROR(...) ::base::make_logic_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_INVALID_ARGUMENT_ERROR(...) ::base::make_invalid_argument_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_DOMAIN_ERROR(...) ::base::make_domain_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_LENGTH_ERROR(...) ::base::make_length_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_OUT_OF_RANGE_ERROR(...) ::base::make_out_of_range_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_RUNTIME_ERROR(...) ::base::make_runtime_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_RANGE_ERROR(...) ::base::make_range_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_OVERFLOW_ERROR(...) ::base::make_overflow_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)
#define BASE_MAKE_CLASS_UNDERFLOW_ERROR(...) ::base::make_underflow_error(BASE_CLASS_DEBUG_INFO, __VA_ARGS__)

namespace base
{
    template <typename... Ts>
    inline std::string format_exception_message(const std::string &debug_info, Ts &&...args)
    {
        return to_string("[", debug_info, "]\n", std::forward<Ts>(args)...);
    }

    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(logic_error);
    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(domain_error);
    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(length_error);
    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(runtime_error);
    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(range_error);
    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(overflow_error);
    BASE_EXCEPTION_MAKE_ERROR_FUNCTION(underflow_error);

    template <typename... Ts>
    inline std::logic_error make_invalid_argument_error(const std::string &debug_info, Ts &&...args)
    {
        return std::invalid_argument(format_exception_message(debug_info, std::forward<Ts>(args)...));
    }

    template <typename... Ts>
    inline std::logic_error make_out_of_range_error(const std::string &debug_info, Ts &&...args)
    {
        return std::out_of_range(format_exception_message(debug_info, std::forward<Ts>(args)...));
    }

} // namespace base
