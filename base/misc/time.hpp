#pragma once

#include <chrono>

namespace base
{
    /// @brief 基础时间类
    /// @tparam ClockType 时钟类型
    template <typename ClockType>
    class Time
    {
    public:
        /// @brief 时钟
        using Clock = ClockType;
        /// @brief 时间段
        using Duration = std::chrono::duration<double>;
        /// @brief 时间点
        using TimePoint = std::chrono::time_point<Clock, Duration>;

        /// @brief 获取当前时间，单位：秒
        /// @return 当前时间
        static inline TimePoint get_current_time() noexcept { return static_cast<TimePoint>(Clock::now()); }

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

    /// @brief 全局时间类，使用std::chrono::steady_clock
    class GlobalTime : public SteadyTime
    {
    public:
        static GlobalTime &get_instance()
        {
            static GlobalTime instance;
            return instance;
        }

    private:
        /// @brief 程序开始时间
        TimePoint m_start_time = get_current_time();

    private:
        inline GlobalTime() = default;
        inline ~GlobalTime() noexcept = default;

    public:
        const TimePoint get_start_time() const noexcept { return m_start_time; }
        const Duration get_time_elapsed() const noexcept { return get_current_time() - m_start_time; }
    };

} // namespace base
