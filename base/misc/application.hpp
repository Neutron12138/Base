#pragma once

#include <cstdlib>
#include "../core/type.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(Application);

    /// @brief 应用
    class Application : virtual public PolymorphicObject
    {
    private:
        /// @brief 程序退出码
        Int32 m_exit_code = EXIT_SUCCESS;
        /// @brief 是否应该退出
        bool m_is_should_quit = false;

    public:
        inline Application() = default;
        inline ~Application() noexcept override = default;

    protected:
        /// @brief 当程序初始化时
        inline virtual void _initialize() {}

        /// @brief 当程序结束时
        inline virtual void _finalize() {}

    public:
        inline void set_exit_code(Int32 exit_code = EXIT_SUCCESS) noexcept { m_exit_code = exit_code; }
        inline Int32 get_exit_code() const noexcept { return m_exit_code; }
        inline void set_is_should_quit(bool is_should_quit) noexcept { m_is_should_quit = is_should_quit; }
        inline bool is_should_quit() const noexcept { return m_is_should_quit; }

    public:
        /// @brief 请求退出
        inline virtual void request_quit() { m_is_should_quit = true; }

        /// @brief 运行程序
        /// @param argc 参数数量
        /// @param argv 参数数组
        inline virtual void run(int argc, char *argv[]) { run(std::vector<std::string>(argv, argv + argc)); }

        /// @brief 运行程序
        /// @param args 参数数组
        inline virtual void run(const std::vector<std::string> &args) { run(); }

        /// @brief 运行程序
        inline virtual void run()
        {
            _initialize();
            _finalize();
        }
    };

} // namespace base
