#pragma once

namespace base
{
    /// @brief 不可拷贝的对象
    class NoncopyableObject
    {
    public:
        NoncopyableObject() = default;
        ~NoncopyableObject() = default;

    public:
        NoncopyableObject(const NoncopyableObject &) = delete;
        NoncopyableObject &operator=(const NoncopyableObject &) = delete;
    };

} // namespace base
