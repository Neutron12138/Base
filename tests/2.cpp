#include <iostream>
#include "../base/base.hpp"

struct A : public base::PolymorphicObject
{
};

struct B : public base::ReferenceObject
{
};

void test_polymorphic_object();
void test_reference_object();
void test_catch_exception();

int main()
{
    auto &time = base::GlobalTime::get_instance();
    base::print_line("program startup time point: ", time.get_start_time().time_since_epoch().count());
    base::print_line();

    base::print_line("size of PolymorphicObject: ", sizeof(base::PolymorphicObject));
    base::print_line("size of ReferenceObject: ", sizeof(base::ReferenceObject));
    base::print_line();

    base::print_line("steady time since epoch: ", base::SteadyTime::get_current_time().time_since_epoch().count());
    base::print_line("system time since epoch: ", base::SystemTime::get_current_time().time_since_epoch().count());
    base::print_line("high resolution time since epoch: ", base::HighResolutionTime::get_current_time().time_since_epoch().count());
    base::print_line();

    auto begin1 = base::SteadyTime::get_current_time();
    test_polymorphic_object();
    auto end1 = base::SteadyTime::get_current_time();
    base::print_line("(raw pointer) total time: ", (end1 - begin1).count(), " seconds");
    base::print_line();

    auto begin2 = base::SteadyTime::get_current_time();
    test_reference_object();
    auto end2 = base::SteadyTime::get_current_time();
    base::print_line("(auto pointer) total time: ", (end2 - begin2).count(), " seconds");
    base::print_line();

    auto begin3 = base::SteadyTime::get_current_time();
    test_catch_exception();
    auto end3 = base::SteadyTime::get_current_time();
    base::print_line("(catch exception) total time: ", (end3 - begin3).count(), " seconds");
    base::print_line();

    base::print_line("time elapsed since program startup: ", time.get_time_elapsed().count(), "seconds");

    return 0;
}

void test_polymorphic_object()
{
    A a1;
    const A a2;

    static_assert(std::is_same_v<A *, decltype(a1.as<A>())>);
    static_assert(std::is_same_v<const A *, decltype(a2.as<A>())>);
    static_assert(std::is_same_v<A *, decltype(base::get_if<A>(&a1))>);
    static_assert(std::is_same_v<const A *, decltype(base::get_if<A>(&a2))>);
    static_assert(std::is_same_v<A *, decltype(base::get_or_error<A>(&a1))>);
    static_assert(std::is_same_v<const A *, decltype(base::get_or_error<A>(&a2))>);

    base::print_line("a1.as<A>: ", a1.as<A>());
    base::print_line("a2.as<A>: ", a2.as<A>());

    base::print_line("get_if<A>(&a1): ", base::get_if<A>(&a1));
    base::print_line("get_if<A>(&a2): ", base::get_if<A>(&a2));

    base::print_line("get_or_error<A>(&a1): ", base::get_or_error<A>(&a1));
    base::print_line("get_or_error<A>(&a2): ", base::get_or_error<A>(&a2));
}

void test_reference_object()
{
    base::Ref<B> b1 = std::make_shared<B>();
    base::Ref<const B> b2 = std::make_shared<B>();

    static_assert(std::is_same_v<base::Ref<B>, decltype(b1->as<B>())>);
    static_assert(std::is_same_v<base::Ref<const B>, decltype(b2->as<B>())>);
    static_assert(std::is_same_v<base::Ref<B>, decltype(base::get_if<B>(b1))>);
    static_assert(std::is_same_v<base::Ref<const B>, decltype(base::get_if<B>(b2))>);
    static_assert(std::is_same_v<base::Ref<B>, decltype(base::get_or_error<B>(b1))>);
    static_assert(std::is_same_v<base::Ref<const B>, decltype(base::get_or_error<B>(b2))>);

    base::print_line("b1->as<B>(): ", b1->as<B>());
    base::print_line("b2->as<B>(): ", b2->as<B>());

    base::print_line("get_if<B>(b1): ", base::get_if<B>(b1));
    base::print_line("get_if<B>(b2): ", base::get_if<B>(b2));

    base::print_line("get_or_error<B>(b1): ", base::get_or_error<B>(b1));
    base::print_line("get_or_error<B>(b2): ", base::get_or_error<B>(b2));
}

void test_catch_exception()
{
    try
    {
        A a;
        base::get_or_error<B>(&a);
    }
    catch (const std::exception &e)
    {
        base::print_line(e.what());
        base::print_line();
    }
}
