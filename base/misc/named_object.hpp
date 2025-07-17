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
        inline ~NamedObject() noexcept override = default;

    protected:
        /// @brief 当对象名更改时
        /// @param old_name 旧名字
        /// @param new_name 新名字
        inline virtual void _on_name_changed(const std::string &old_name, const std::string &new_name) {}

    public:
        inline const std::string &get_name() const { return m_name; }
        inline void set_name(const std::string &new_name)
        {
            if (m_name == new_name)
                return;

            std::string old_name = std::move(m_name);
            m_name = new_name;
            _on_name_changed(std::move(old_name), m_name);
        }
    };

} // namespace base
