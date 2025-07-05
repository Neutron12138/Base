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
    public:
        inline Notifiable() = default;
        inline ~Notifiable() override = default;

    protected:
        /// @brief 被通知时
        /// @param what 具体通知
        virtual void _on_notified(Int64 what) {}

    public:
        /// @brief 请求处理通知
        /// @param what 具体通知
        virtual void request_notification(Int64 what)
        {
            _on_notified(what);
        }
    };

    /// @brief 通知一个对象
    /// @param notifiable 待通知对象
    /// @param what 具体通知
    inline void notify(const NotifiableRef &notifiable, Int64 what)
    {
        notifiable->request_notification(what);
    }

} // namespace base
