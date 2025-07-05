#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "../core/type.hpp"
#include "../core/ref.hpp"
#include "../core/time.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(Logger);

    /// @brief 日志输出器
    class Logger : public SystemTime,
                   public PolymorphicObject
    {
    public:
        /// @brief 日志等级
        enum class LogLevel : Int32
        {
            /// @brief 未知
            Unknown,
            /// @brief 调试
            Debug,
            /// @brief 信息
            Info,
            /// @brief 警告
            Warning,
            /// @brief 错误
            Error,
        };

        /// @brief 输出流引用包装器
        using OStreamRefWrapper = RefWrapper<std::ostream>;
        /// @brief 输出流数组
        using OStreamArray = std::vector<OStreamRefWrapper>;
        /// @brief 输出流迭代器
        using OStreamConstIterator = OStreamArray::const_iterator;

        template <typename... T>
        static std::string format_log(LogLevel level, T... args);

    private:
        /// @brief 日志流对象，所有日志都会输入进去
        std::stringstream m_log_stream;
        /// @brief 是否启用标准输出（仅std::cout）
        bool m_is_standard_output_enabled = true;
        /// @brief 是否启用额外输出流
        bool m_is_extra_ostream_enabled = true;
        /// @brief 额外输出流引用数组
        OStreamArray m_extra_ostreams;

    public:
        inline Logger() = default;
        inline ~Logger() override = default;

    public:
        inline const std::stringstream &get_log_stream() const { return m_log_stream; }
        inline void set_standard_output_enabled(bool enabled) { m_is_standard_output_enabled = enabled; }
        inline bool is_standard_output_enabled() const { return m_is_standard_output_enabled; }
        inline void set_extra_ostream_enabled(bool enabled) { m_is_extra_ostream_enabled = enabled; }
        inline bool is_extra_ostream_enabled() const { return m_is_extra_ostream_enabled; }
        inline const OStreamArray &get_extra_ostreams() const { return m_extra_ostreams; }

    protected:
        inline void _clear_extra_ostreams() { m_extra_ostreams.clear(); }
        inline void _add_extra_ostream(const OStreamRefWrapper &ostream) { m_extra_ostreams.push_back(ostream); }
        inline void _remove_extra_ostream(const OStreamConstIterator &iter) { m_extra_ostreams.erase(iter); }

        /// @brief 输出日志
        /// @param content 日志内容
        virtual void _output_log(const std::string &content);

    public:
        inline void add_extra_ostream(const OStreamRefWrapper &ostream) { _add_extra_ostream(ostream); }
        inline void clear_extra_ostreams() { _clear_extra_ostreams(); }

    public:
        /// @brief 输出Unknown日志
        /// @tparam ...T 参数类型列表
        /// @param ...args 参数列表
        template <typename... T>
        void logu(T... args);

        /// @brief 输出Debug日志
        /// @tparam ...T 参数类型列表
        /// @param ...args 参数列表
        template <typename... T>
        void logd(T... args);

        /// @brief 输出Info日志
        /// @tparam ...T 参数类型列表
        /// @param ...args 参数列表
        template <typename... T>
        void logi(T... args);

        /// @brief 输出Warning日志
        /// @tparam ...T 参数类型列表
        /// @param ...args 参数列表
        template <typename... T>
        void logw(T... args);

        /// @brief 输出Error日志
        /// @tparam ...T 参数类型列表
        /// @param ...args 参数列表
        template <typename... T>
        void loge(T... args);
    };

    std::ostream &operator<<(std::ostream &os, Logger::LogLevel level);

} // namespace base
