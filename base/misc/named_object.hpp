#pragma once

#include <string>
#include "../core/ref.hpp"
#include "../core/polymorphic_object.hpp"

namespace base
{
    BASE_DECLARE_REF_TYPE(Notifiable);

    /// @brief 带名字的对象
    class NamedObject : virtual public PolymorphicObject
    {
    private:
        /// @brief 对象名
        std::string m_name;

    public:
        inline NamedObject(const std::string &name = {}) : m_name(name) {}
        inline ~NamedObject() override = default;

    protected:
        /// @brief 当对象名更改时
        /// @param old_name 旧名字
        /// @param new_name 新名字
        virtual void _on_name_changed(const std::string &old_name, const std::string &new_name) {}

        /// @brief 直接设置对象名
        /// @param name 对象名
        inline void _set_name(const std::string &name) { m_name = name; }

    public:
        inline const std::string &get_name() const { return m_name; }

        virtual void set_name(const std::string &new_name)
        {
            if (m_name == new_name)
                return;

            std::string old_name = m_name;
            m_name = new_name;
            _on_name_changed(old_name, new_name);
        }
    };

} // namespace base
