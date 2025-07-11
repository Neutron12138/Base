#pragma once

#include "../core/type.hpp"
#include "../core/ref.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(Notifiable);

    /// @brief 可通知对象
    class Notifiable : virtual public PolymorphicObject
    {
    private:
        /// @brief 是否启用通知处理
        bool m_is_notification_enabled = true;

    public:
        inline Notifiable() = default;
        inline ~Notifiable() noexcept override = default;

    protected:
        /// @brief 被通知时
        /// @param notification 具体通知
        virtual void _on_notified(Int64 notification) {}

    public:
        inline bool is_notification_enabled() const noexcept { return m_is_notification_enabled; }
        inline void set_notification_enabled(bool is_notification_enabled) noexcept { m_is_notification_enabled = is_notification_enabled; }

    public:
        /// @brief 通知该对象
        /// @param notification 具体通知
        inline virtual void receive_notification(Int64 notification)
        {
            if (m_is_notification_enabled)
                _on_notified(notification);
        }
    };

    /// @brief 通知一个对象
    /// @param notifiable 待通知对象
    /// @param notification 具体通知
    inline void send_notification(Notifiable &notifiable, Int64 notification)
    {
        notifiable.receive_notification(notification);
    }

} // namespace base
