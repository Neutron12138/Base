#pragma once

#include <chrono>

namespace base
{
    /// @brief 时间
    /// @tparam ClockType 时钟类型
    template <typename ClockType>
    class Time
    {
    public:
        /// @brief 时钟
        using Clock = ClockType;
        /// @brief 时间点
        using TimePoint = typename Clock::time_point;
        /// @brief 时间段
        using Duration = std::chrono::duration<double>;

        /// @brief 获取当前时间
        /// @return 当前时间
        static inline TimePoint get_current_time() { return Clock::now(); }

    public:
        inline Time() = default;
        inline ~Time() = default;
    };

    /// @brief 稳定时间
    using SteadyTime = Time<std::chrono::steady_clock>;
    /// @brief 系统时间
    using SystemTime = Time<std::chrono::system_clock>;
    /// @brief 高精度时间
    using HighResolutionTime = Time<std::chrono::high_resolution_clock>;

} // namespace base
