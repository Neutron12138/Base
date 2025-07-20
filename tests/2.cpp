#include <iostream>
#include "../base/base.hpp"

struct A : public base::PolymorphicObject
{
};

struct B : public base::ReferenceObject
{
};

int main()
{
    A a1;
    const A a2;

    static_assert(std::is_same_v<A *, decltype(a1.as<A>())>);
    static_assert(std::is_same_v<const A *, decltype(a2.as<A>())>);
    static_assert(std::is_same_v<A *, decltype(base::get_if<A>(&a1))>);
    static_assert(std::is_same_v<const A *, decltype(base::get_if<A>(&a2))>);
    static_assert(std::is_same_v<A *, decltype(base::get_or_error<A>(&a1))>);
    static_assert(std::is_same_v<const A *, decltype(base::get_or_error<A>(&a2))>);

    auto begin1 = base::SteadyTime::get_current_time();

    base::print_line("a1.as<A>: ", a1.as<A>());
    base::print_line("a2.as<A>: ", a2.as<A>());

    base::print_line("base::get_if<A>(&a1): ", base::get_if<A>(&a1));
    base::print_line("base::get_if<A>(&a2): ", base::get_if<A>(&a2));

    base::print_line("base::get_or_error<A>(&a1): ", base::get_or_error<A>(&a1));
    base::print_line("base::get_or_error<A>(&a2): ", base::get_or_error<A>(&a2));

    auto end1 = base::SteadyTime::get_current_time();
    base::print_line("(raw pointer) total time: ", (end1 - begin1).count(), " seconds");

    base::Ref<B> b1 = std::make_shared<B>();
    base::Ref<const B> b2 = std::make_shared<B>();

    static_assert(std::is_same_v<base::Ref<B>, decltype(b1->as<B>())>);
    static_assert(std::is_same_v<base::Ref<const B>, decltype(b2->as<B>())>);
    static_assert(std::is_same_v<base::Ref<B>, decltype(base::get_if<B>(b1))>);
    static_assert(std::is_same_v<base::Ref<const B>, decltype(base::get_if<B>(b2))>);
    static_assert(std::is_same_v<base::Ref<B>, decltype(base::get_or_error<B>(b1))>);
    static_assert(std::is_same_v<base::Ref<const B>, decltype(base::get_or_error<B>(b2))>);

    auto begin2 = base::SteadyTime::get_current_time();

    base::print_line("b1->as<B>(): ", b1->as<B>());
    base::print_line("b2->as<B>(): ", b2->as<B>());

    base::print_line("base::get_if<B>(b1): ", base::get_if<B>(b1));
    base::print_line("base::get_if<B>(b2): ", base::get_if<B>(b2));

    base::print_line("base::get_or_error<B>(b1): ", base::get_or_error<B>(b1));
    base::print_line("base::get_or_error<B>(b2): ", base::get_or_error<B>(b2));

    auto end2 = base::SteadyTime::get_current_time();
    base::print_line("(auto pointer) total time: ", (end2 - begin2).count(), " seconds");

    return 0;
}
