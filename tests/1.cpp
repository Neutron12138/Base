#include <iostream>
#define BASE_DEFINE_FLOAT_TYPE
#include "../base/base.hpp"

struct A : public base::PolymorphicObject
{
};

struct B : public base::ReferenceObject
{
};

class MyApp : public base::Application
{
private:
    base::SystemTime time;

private:
    void _test_polymorphic()
    {
        A a1;
        const A a2;

        static_assert(std::is_same_v<A *, decltype(a1.as<A>())>);
        std::cout << "a1.as<A>: " << a1.as<A>() << std::endl;
        static_assert(std::is_same_v<const A *, decltype(a2.as<A>())>);
        std::cout << "a2.as<A>: " << a2.as<A>() << std::endl;

        static_assert(std::is_same_v<A *, decltype(base::get_if<A>(&a1))>);
        std::cout << "base::get_if<A>(&a1): " << base::get_if<A>(&a1) << std::endl;
        static_assert(std::is_same_v<const A *, decltype(base::get_if<A>(&a2))>);
        std::cout << "base::get_if<A>(&a2): " << base::get_if<A>(&a2) << std::endl;

        static_assert(std::is_same_v<A *, decltype(base::get_or_error<A>(&a1))>);
        std::cout << "base::get_or_error<A>(&a1): " << base::get_or_error<A>(&a1) << std::endl;
        static_assert(std::is_same_v<const A *, decltype(base::get_or_error<A>(&a2))>);
        std::cout << "base::get_or_error<A>(&a2): " << base::get_or_error<A>(&a2) << std::endl;

        base::Ref<B> b1 = std::make_shared<B>();
        base::Ref<const B> b2 = std::make_shared<B>();

        static_assert(std::is_same_v<base::Ref<B>, decltype(b1->as<B>())>);
        std::cout << "b1->as<B>(): " << b1->as<B>() << std::endl;
        static_assert(std::is_same_v<base::Ref<const B>, decltype(b2->as<B>())>);
        std::cout << "b2->as<B>(): " << b2->as<B>() << std::endl;

        static_assert(std::is_same_v<base::Ref<B>, decltype(base::get_if<B>(b1))>);
        std::cout << "base::get_if<B>(b1): " << base::get_if<B>(b1) << std::endl;
        static_assert(std::is_same_v<base::Ref<const B>, decltype(base::get_if<B>(b2))>);
        std::cout << "base::get_if<B>(b2): " << base::get_if<B>(b2) << std::endl;

        static_assert(std::is_same_v<base::Ref<B>, decltype(base::get_or_error<B>(b1))>);
        std::cout << "base::get_or_error<B>(b1): " << base::get_or_error<B>(b1) << std::endl;
        static_assert(std::is_same_v<base::Ref<const B>, decltype(base::get_or_error<B>(b2))>);
        std::cout << "base::get_or_error<B>(b2): " << base::get_or_error<B>(b2) << std::endl;

        std::cout << std::endl;
    }

protected:
    void _initialize() override
    {
        std::cout << "Float32: " << sizeof(base::Float32) << std::endl
                  << "Float64: " << sizeof(base::Float64) << std::endl
                  << "Float128: " << sizeof(base::Float128) << std::endl
                  << std::endl;

        std::cout << "test to_string:" << std::endl
                  << base::to_string() << std::endl
                  << base::to_string(123) << std::endl
                  << base::to_string("good", " ", "job") << std::endl
                  << std::endl;

        std::cout << "read string from \"1.txt\":" << std::endl
                  << base::read_string_from_file("1.txt") << std::endl
                  << std::endl;

        auto buffer = base::read_bytes_from_file("1.txt");
        std::cout << "read bytes from \"1.txt\":" << std::endl
                  << "buffer size: " << buffer.size() << std::endl
                  << std::string(buffer.begin(), buffer.end()) << std::endl
                  << std::endl;

        std::cout << "sizeof(base::PolymorphicObject): " << sizeof(base::PolymorphicObject) << std::endl
                  << "sizeof(base::ReferenceObject): " << sizeof(base::ReferenceObject) << std::endl
                  << std::endl;

        auto beg = base::SteadyTime::get_current_time();
        _test_polymorphic();
        auto end = base::SteadyTime::get_current_time();
        auto elapse = end - beg;
        std::cout << elapse.count() << std::endl
                  << std::endl;
    }
};

int main(int argc, char *argv[])
{
    MyApp app;
    app.run(argc, argv);
    return app.get_exit_code();
}
