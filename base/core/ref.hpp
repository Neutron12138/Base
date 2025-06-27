#pragma once

#include <memory>
#include <functional>

#define BASE_DECLARE_REF_TYPE(class_name)            \
    class class_name;                                \
    using class_name##Ref = ::base::Ref<class_name>; \
    using class_name##WeakRef = ::base::WeakRef<class_name>;

namespace base
{
    /// @brief 对象引用，同std::shared_ptr
    /// @tparam T 对象类型
    template <typename T>
    using Ref = std::shared_ptr<T>;

    /// @brief 对象弱引用，同std::weak_ptr
    /// @tparam T 对象类型
    template <typename T>
    using WeakRef = std::weak_ptr<T>;

    /// @brief 独占引用，同std::unique_ptr
    /// @tparam T 对象类型
    template <typename T>
    using UniqueRef = std::unique_ptr<T>;

    /// @brief 引用包装器，同std::reference_wrapper
    /// @tparam T 对象类型
    template <typename T>
    using RefWrapper = std::reference_wrapper<T>;

    /// @brief 任意对象的引用，不是std::any的引用
    using AnyRef = Ref<void>;
    /// @brief 任意对象的弱引用，不是std::any的弱引用
    using AnyWeakRef = WeakRef<void>;

} // namespace base
