#pragma once

#include "../core/type.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(RTTIObject);

    /// @brief 能够在运行时获取类型的对象
    class RTTIObject : virtual public PolymorphicObject
    {
    public:
        inline RTTIObject() = default;
        inline ~RTTIObject() override = default;

    public:
        /// @brief 获取对象类型
        /// @return 对象类型
        inline virtual Int64 get_object_type() const = 0;
    };

} // namespace base
