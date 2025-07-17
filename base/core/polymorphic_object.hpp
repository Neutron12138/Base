#pragma once

#include "exception.hpp"
#include "ref.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(PolymorphicObject);

    /// @brief 多态对象，有虚函数表（8字节）
    class PolymorphicObject
    {
    public:
        inline PolymorphicObject() = default;
        inline virtual ~PolymorphicObject() noexcept = default;

    public:
        /// @brief 检查是否能转换成指定类型
        /// @tparam T 目标类型
        /// @return 是否能转换
        template <typename T>
        inline bool is() const noexcept
        {
            static_assert(std::is_base_of_v<PolymorphicObject, T>,
                          "The target type is not derived from PolymorphicObject");
            return dynamic_cast<const T *>(this);
        }

        /// @brief 转换为指定类型
        /// @tparam T 目标类型
        /// @return 转换后的指针
        template <typename T>
        inline T *as() noexcept
        {
            static_assert(std::is_base_of_v<PolymorphicObject, T>,
                          "The target type is not derived from PolymorphicObject");
            return dynamic_cast<T *>(this);
        }

        /// @brief 转换为指定类型
        /// @tparam T 目标类型
        /// @return 转换后的指针
        template <typename T>
        inline const T *as() const noexcept
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
    inline T *get_if(U *ptr) noexcept
    {
        static_assert(std::is_base_of_v<PolymorphicObject, T>,
                      "The target type is not derived from PolymorphicObject");
        return dynamic_cast<T *>(ptr);
    }

    /// @brief 转换类型
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    inline const T *get_if(const U *ptr) noexcept
    {
        static_assert(std::is_base_of_v<PolymorphicObject, T>,
                      "The target type is not derived from PolymorphicObject");
        return dynamic_cast<const T *>(ptr);
    }

    /// @brief 转换类型，失败则抛出异常
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    inline T *get_or_error(U *ptr)
    {
        static_assert(std::is_base_of_v<PolymorphicObject, T>,
                      "The target type is not derived from PolymorphicObject");
        T *p = dynamic_cast<T *>(ptr);

        if (!p)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to convert to specified type, pointer: ", ptr);

        return p;
    }

    /// @brief 转换类型，失败则抛出异常
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    inline const T *get_or_error(const U *ptr)
    {
        static_assert(std::is_base_of_v<PolymorphicObject, T>,
                      "The target type is not derived from PolymorphicObject");
        const T *p = dynamic_cast<const T *>(ptr);

        if (!p)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to convert to specified type, pointer: ", ptr);

        return p;
    }

} // namespace base
