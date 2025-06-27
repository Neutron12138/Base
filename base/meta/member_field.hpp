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
        using ConstPtr = const Type(Class::*);

    private:
        /// @brief 指针
        Ptr m_ptr;
        /// @brief const指针
        ConstPtr m_const_ptr;

    public:
        MemberField(Ptr ptr) : FieldBase(false), m_ptr(ptr) {}
        MemberField(ConstPtr ptr) : FieldBase(true), m_const_ptr(ptr) {}
        ~MemberField() override = default;

    public:
        Ptr get_ptr() const { return m_ptr; }
        ConstPtr get_const_ptr() const { return m_const_ptr; }

    public:
        std::any get(void *object) const override
        {
            if (is_const())
                return reinterpret_cast<Class *>(object)->*m_const_ptr;
            else
                return reinterpret_cast<Class *>(object)->*m_ptr;
        }

        std::any get(const void *object) const override
        {
            if (is_const())
                return reinterpret_cast<const Class *>(object)->*m_const_ptr;
            else
                return reinterpret_cast<const Class *>(object)->*m_ptr;
        }

        void set(void *object, const std::any &value) const override
        {
            if (is_const())
                throw BASE_MAKE_RUNTIME_ERROR("Cannot set a const field, pointer: ", m_const_ptr);

            reinterpret_cast<Class *>(object)->*m_ptr = std::any_cast<T>(value);
        }
    };

} // namespace base
