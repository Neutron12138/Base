#pragma once

namespace base
{
    /// @brief 不可拷贝的对象
    class NoncopyableObject
    {
    public:
        inline NoncopyableObject() = default;
        inline ~NoncopyableObject() = default;

    public:
        NoncopyableObject(const NoncopyableObject &) = delete;
        NoncopyableObject &operator=(const NoncopyableObject &) = delete;
    };

} // namespace base
