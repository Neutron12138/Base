#pragma once

#include "polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(ReferenceObject);

    /// @brief 引用对象，必须用std::shared_ptr创建
    class ReferenceObject : virtual public PolymorphicObject,
                            public std::enable_shared_from_this<ReferenceObject>
    {
    public:
        inline ReferenceObject() = default;
        inline ~ReferenceObject() noexcept override = default;

    public:
        /// @brief 转换为指定类型
        /// @tparam T 目标类型
        /// @return 转换后的指针
        template <typename T>
        inline Ref<T> as() noexcept
        {
            static_assert(std::is_base_of_v<ReferenceObject, T>,
                          "The target type is not derived from ReferenceObject");
            return std::dynamic_pointer_cast<T>(shared_from_this());
        }

        /// @brief 转换为指定类型
        /// @tparam T 目标类型
        /// @return 转换后的指针
        template <typename T>
        inline Ref<const T> as() const noexcept
        {
            static_assert(std::is_base_of_v<ReferenceObject, T>,
                          "The target type is not derived from ReferenceObject");
            return std::dynamic_pointer_cast<const T>(shared_from_this());
        }
    };

    /// @brief 转换类型
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    Ref<T> get_if(const Ref<U> &ptr) noexcept
    {
        static_assert(std::is_base_of_v<ReferenceObject, T>,
                      "The target type is not derived from ReferenceObject");
        return std::dynamic_pointer_cast<T>(ptr);
    }

    /// @brief 转换类型
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    Ref<const T> get_if(const Ref<const U> &ptr) noexcept
    {
        static_assert(std::is_base_of_v<ReferenceObject, T>,
                      "The target type is not derived from ReferenceObject");
        return std::dynamic_pointer_cast<const T>(ptr);
    }

    /// @brief 转换类型，失败则抛出异常
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    Ref<T> get_or_error(const Ref<U> &ptr)
    {
        static_assert(std::is_base_of_v<ReferenceObject, T>,
                      "The target type is not derived from ReferenceObject");

        Ref<T> p = std::dynamic_pointer_cast<T>(ptr);
        if (!p)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to convert to specified type, pointer: ", ptr.get());

        return p;
    }

    /// @brief 转换类型，失败则抛出异常
    /// @tparam T 目标类型
    /// @tparam U 源类型
    /// @param ptr 指针
    /// @return 转换后指针
    template <typename T, typename U>
    Ref<const T> get_or_error(const Ref<const U> &ptr)
    {
        static_assert(std::is_base_of_v<ReferenceObject, T>,
                      "The target type is not derived from ReferenceObject");

        Ref<const T> p = std::dynamic_pointer_cast<const T>(ptr);
        if (!p)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to convert to specified type, pointer: ", ptr.get());

        return p;
    }

} // namespace base
