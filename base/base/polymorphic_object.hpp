#pragma once

#include "exception.hpp"

namespace base
{
    /// @brief 多态对象，有虚函数表（8字节）
    class PolymorphicObject
    {
    protected:
        PolymorphicObject() = default;

    public:
        virtual ~PolymorphicObject() = default;

    public:
        /// @brief 检查是否能转换成指定类型
        /// @tparam T 目标类型
        /// @return 是否能转换
        template <typename T>
        bool is() const noexcept
        {
            static_assert(std::is_base_of_v<PolymorphicObject, T>,
                          "The target type is not derived from PolymorphicObject");
            return dynamic_cast<const T *>(this);
        }
    };

    /// @brief 转换类型
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    T *get_if(const U *ptr) noexcept
    {
        static_assert(std::is_base_of_v<PolymorphicObject, T>,
                      "The target type is not derived from PolymorphicObject");
        U *p = const_cast<U *>(ptr);
        return dynamic_cast<T *>(p);
    }

    /// @brief 转换类型，失败则抛出异常
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    T *get_or_error(const U *ptr)
    {
        static_assert(std::is_base_of_v<PolymorphicObject, T>,
                      "The target type is not derived from PolymorphicObject");
        U *p = const_cast<U *>(ptr);
        T *p2 = dynamic_cast<T *>(p);

        if (!p2)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to convert to specified type, pointer: ", ptr);

        return p2;
    }

} // namespace base
