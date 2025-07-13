#pragma once

#include <utility>
#include "../core/type.hpp"
#include "../core/ref.hpp"
#include "../core/noncopyable_object.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(Resource);

    /// @brief 不可拷贝的资源对象
    class Resource : public NoncopyableObject,
                     virtual public PolymorphicObject
    {
    public:
        inline Resource() = default;
        inline ~Resource() noexcept override = default;
        BASE_DELETE_COPY_FUNCTION(Resource);

    public:
        /// @brief 获取资源类型
        /// @return 资源类型枚举
        virtual Int64 get_resource_type() const = 0;

        /// @brief 检查资源是否有效
        /// @return 资源是否有效
        virtual bool is_valid() const = 0;
    };

} // namespace base
