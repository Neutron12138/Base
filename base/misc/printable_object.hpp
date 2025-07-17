#pragma once

#include "../core/to_string.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(PrintableObject);

    /// @brief 可打印的对象
    class PrintableObject : virtual public PolymorphicObject
    {
    public:
        inline PrintableObject() = default;
        inline ~PrintableObject() noexcept override = default;

    public:
        /// @brief 转换成字符串
        /// @return 转换后的字符串
        inline virtual std::string to_string() const
        {
            return ::base::to_string("PrintableObject@", this);
        }
    };

    inline std::ostream &operator<<(std::ostream &os, const PrintableObject &printable)
    {
        os << printable.to_string();
        return os;
    }

} // namespace base
