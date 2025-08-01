#pragma once

#include <chrono>

namespace base
{
    /// @brief 基础时间类
    /// @tparam ClockT 时钟类型
    template <typename ClockT>
    class Time
    {
    public:
        /// @brief 时钟
        using Clock = ClockT;
        /// @brief 时间段
        using Duration = std::chrono::duration<double>;
        /// @brief 时间点
        using TimePoint = std::chrono::time_point<Clock, Duration>;

        /// @brief 获取当前时间，单位：秒
        /// @return 当前时间
        static inline TimePoint get_current_time() { return std::chrono::time_point_cast<Duration>(Clock::now()); }

    public:
        inline Time() = default;
        inline ~Time() noexcept = default;
    };

    /// @brief 稳定时间
    using SteadyTime = Time<std::chrono::steady_clock>;
    /// @brief 系统时间
    using SystemTime = Time<std::chrono::system_clock>;
    /// @brief 高精度时间
    using HighResolutionTime = Time<std::chrono::high_resolution_clock>;

    /// @brief 获取自第一次调用以来经过的时间，单位：秒
    /// @return 自第一次调用以来经过的时间
    inline double get_elapsed_seconds()
    {
        static const auto first_call_time = SteadyTime::get_current_time();
        return (SteadyTime::get_current_time() - first_call_time).count();
    }

} // namespace base
