#pragma once

#include <any>
#include "../core/ref.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    class FieldBase;
    using FieldBaseRef = Ref<FieldBase>;
    using FieldBaseWeakRef = WeakRef<FieldBase>;

    /// @brief 属性基类
    class FieldBase : public PolymorphicObject
    {
    public:
        FieldBase() = default;
        ~FieldBase() override = default;

    public:
        /// @brief 获取属性
        /// @param object 对象
        /// @return 结果
        virtual std::any get(void *object) const = 0;

        /// @brief 设置属性
        /// @param object 对象
        /// @param value 值
        virtual void set(void *object, const std::any &value) const = 0;
    };

} // namespace base
