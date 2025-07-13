#pragma once

#define BASE_DELETE_COPY_FUNCTION(class_name) \
    class_name(const class_name &) = delete;  \
    class_name &operator=(const class_name &) = delete;

namespace base
{
    /// @brief 不可拷贝的对象
    class NoncopyableObject
    {
    public:
        inline NoncopyableObject() = default;
        inline ~NoncopyableObject() noexcept = default;

    public:
        BASE_DELETE_COPY_FUNCTION(NoncopyableObject);
    };

} // namespace base
