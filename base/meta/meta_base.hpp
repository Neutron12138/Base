#pragma once

#include <any>
#include <tuple>
#include "../core/ref.hpp"
#include "../core/polymorphic_object.hpp"
#include "../core/exception.hpp"

namespace base
{
    class MetaBase;
    using MetaBaseRef = Ref<MetaBase>;
    using MetaBaseWeakRef = WeakRef<MetaBase>;

    /// @brief 元基类
    class MetaBase : public PolymorphicObject
    {
    private:
        /// @brief 是否为const
        bool m_is_const;

    public:
        MetaBase(bool is_const) : m_is_const(is_const) {}
        ~MetaBase() override = default;

    public:
        bool is_const() const { return m_is_const; }
    };

} // namespace base
