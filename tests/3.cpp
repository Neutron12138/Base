#include <iostream>
#include "../base/base.hpp"

struct A : base::PolymorphicObject
{
    virtual void func() = 0;
};

struct B : public A
{
    std::size_t count = 0;
    void func() override { count++; }
};

int main()
{
    auto &time = base::GlobalTime::get_instance();

    auto begin1 = time.get_current_time();
    for (std::size_t i = 0; i < 10000; i++)
        base::to_string("This is the ", i, "th cycle");
    auto end1 = time.get_current_time();
    auto delta1 = (end1 - begin1).count();
    base::print_line("total: ", delta1, ", average: ", delta1 / 10000.0);

    B b;
    auto begin2 = time.get_current_time();
    for (std::size_t i = 0; i < 10000; i++)
        base::get_if<A>(&b)->func();
    auto end2 = time.get_current_time();
    auto delta2 = (end2 - begin2).count();
    base::print_line("total: ", delta2, ", average: ", delta2 / 10000.0);

    base::print_line("ratio: ", delta1 / delta2);

    return 0;
}
