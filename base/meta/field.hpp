#pragma once

#include "field_base.hpp"

namespace base
{
    template <typename T>
    class Field;
    template <typename T>
    using FieldRef = Ref<Field<T>>;
    template <typename T>
    using FieldWeakRef = WeakRef<Field<T>>;

    /// @brief 普通属性
    /// @tparam T 类型
    template <typename T>
    class Field : public FieldBase
    {
    public:
        using Type = T;
        using Ptr = Type *;

    private:
        /// @brief 指针
        Ptr m_ptr;

    public:
        Field(Ptr ptr) : m_ptr(ptr) {}
        ~Field() override = default;

    public:
        Ptr get_ptr() const { return m_ptr; }

    public:
        std::any get(void *object) const override
        {
            return *m_ptr;
        }

        void set(void *object, const std::any &value) const override
        {
            *m_ptr = std::any_cast<T>(value);
        }
    };

} // namespace base
