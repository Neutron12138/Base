#pragma once

#include "field_base.hpp"

namespace base
{
    template <typename T, typename C>
    class MemberField;
    template <typename T, typename C>
    using MemberFieldRef = Ref<MemberField<T, C>>;
    template <typename T, typename C>
    using MemberFieldWeakRef = WeakRef<MemberField<T, C>>;

    /// @brief 成员属性
    /// @tparam T 类型
    /// @tparam C 类类型
    template <typename T, typename C>
    class MemberField : public FieldBase
    {
    public:
        using Type = T;
        using Class = C;
        using Ptr = Type(Class::*);

    private:
        /// @brief 指针
        Ptr m_ptr;

    public:
        MemberField(Ptr ptr) : m_ptr(ptr) {}
        ~MemberField() override = default;

    public:
        Ptr get_ptr() const { return m_ptr; }

    public:
        std::any get(void *object) const override
        {
            return reinterpret_cast<Class *>(object)->*m_ptr;
        }

        void set(void *object, const std::any &value) const override
        {
            reinterpret_cast<Class *>(object)->*m_ptr = std::any_cast<T>(value);
        }
    };

} // namespace base
