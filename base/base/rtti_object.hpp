#pragma once

#include "type.hpp"
#include "reference_object.hpp"

namespace base
{
    /// @brief 能够在运行时获取类型的对象
    class RTTIObject : public ReferenceObject
    {
    public:
        RTTIObject() = default;
        ~RTTIObject() override = default;

    public:
        /// @brief 获取对象类型
        /// @return 对象类型
        inline virtual Int64 get_object_type() const = 0;
    };

} // namespace base
