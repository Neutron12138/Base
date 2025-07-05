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
        inline ~Application() override = default;

    protected:
        /// @brief 当程序初始化时
        virtual void _on_initialize() {}

        /// @brief 当程序结束时
        virtual void _on_finalize() {}

    public:
        inline void set_exit_code(Int32 exit_code = EXIT_FAILURE) { m_exit_code = exit_code; }
        inline Int32 get_exit_code() const { return m_exit_code; }
        inline bool is_should_quit() const { return m_is_should_quit; }

    protected:
        /// @brief 设置是否应该退出
        /// @param is_should_quit 是否应该退出
        inline void _set_is_should_quit(bool is_should_quit) { m_is_should_quit = is_should_quit; }

    public:
        /// @brief 请求退出
        virtual void request_quit()
        {
            m_is_should_quit = true;
        }

        /// @brief 运行逻辑
        virtual void run() = 0;
    };

} // namespace base
