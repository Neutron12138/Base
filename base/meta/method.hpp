#pragma once

#include <tuple>
#include "method_base.hpp"

namespace base
{
    template <typename, typename...>
    class Method;
    template <typename R, typename... T>
    using MethodRef = Ref<Method<R, T...>>;
    template <typename R, typename... T>
    using MethodWeakRef = WeakRef<Method<R, T...>>;

    /// @brief 普通方法
    /// @tparam R 返回值类型
    /// @tparam ...T 参数类型
    template <typename R, typename... T>
    class Method : public MethodBase
    {
    public:
        using Ret = R;
        using ArgsTuple = std::tuple<T...>;
        using Ptr = Ret (*)(T...);

    private:
        /// @brief 指针
        Ptr m_ptr;

    public:
        Method(Ptr ptr) : m_ptr(ptr) {}
        ~Method() override = default;

    public:
        Ptr get_ptr() const { return m_ptr; }

    public:
        std::any invoke(void *object, const std::any &args) const override
        {
            auto tuple = std::any_cast<ArgsTuple>(args);
            auto impl = [this](auto... args) -> Ret
            {
                return std::invoke(m_ptr, args...);
            };

            if constexpr (std::is_void_v<Ret>)
            {
                std::apply(impl, tuple);
                return {};
            }
            else
            {
                return std::apply(impl, tuple);
            }
        }
    };

} // namespace base
