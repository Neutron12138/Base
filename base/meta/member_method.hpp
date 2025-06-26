#pragma once

#include "method_base.hpp"

namespace base
{
    template <typename, typename, typename...>
    class MemberMethod;
    template <typename R, typename C, typename... T>
    using MemberMethodRef = Ref<MemberMethod<R, C, T...>>;
    template <typename R, typename C, typename... T>
    using MemberMethodWeakRef = WeakRef<MemberMethod<R, C, T...>>;

    /// @brief 成员方法
    /// @tparam R 返回值类型
    /// @tparam C 类类型
    /// @tparam ...T 参数类型
    template <typename R, typename C, typename... T>
    class MemberMethod : public MethodBase
    {
    public:
        using Ret = R;
        using Class = C;
        using ArgsTuple = std::tuple<T...>;
        using Ptr = Ret (Class::*)(T...);
        using PtrConst = Ret (Class::*)(T...) const;

    private:
        /// @brief 非const方法指针
        Ptr m_ptr;
        /// @brief const方法指针
        PtrConst m_ptr_const;

    public:
        MemberMethod(Ptr ptr) : m_ptr(ptr) {}
        MemberMethod(PtrConst ptr_const) : m_ptr_const(ptr_const) {}
        ~MemberMethod() override = default;

    public:
        Ptr get_ptr() const { return m_ptr; }
        PtrConst get_ptr_const() const { return m_ptr_const; }

    public:
        std::any invoke(void *object, const std::any &args) const override
        {
            auto tuple = std::any_cast<ArgsTuple>(args);
            auto impl = [this, object](auto... args) -> Ret
            {
                if (m_ptr)
                    return std::invoke(m_ptr, reinterpret_cast<Class *>(object), args...);
                else
                    return std::invoke(m_ptr_const, reinterpret_cast<Class *>(object), args...);
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
