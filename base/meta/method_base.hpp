#pragma once

#include <any>
#include "../core/ref.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    class MethodBase;
    using MethodBaseRef = Ref<MethodBase>;
    using MethodBaseWeakRef = WeakRef<MethodBase>;

    /// @brief 方法基类
    class MethodBase : public MetaBase
    {
    public:
        MethodBase(bool is_const) : MetaBase(is_const) {}
        ~MethodBase() override = default;

    public:
        /// @brief 调用方法
        /// @param object 对象
        /// @param args 参数列表
        /// @return 返回值
        virtual std::any invoke(void *object, const std::any &args) const = 0;

        /// @brief 调用方法
        /// @param object 对象
        /// @param args 参数列表
        /// @return 返回值
        virtual std::any invoke(const void *object, const std::any &args) const = 0;
    };

} // namespace base
