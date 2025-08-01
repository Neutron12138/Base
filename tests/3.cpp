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
    base::get_elapsed_seconds();

    double begin1 = base::get_elapsed_seconds();
    for (std::size_t i = 0; i < 10000; i++)
        base::to_string("This is the ", i, "th cycle");
    double end1 = base::get_elapsed_seconds();
    double delta1 = end1 - begin1;
    base::print_line("total: ", delta1, ", average: ", delta1 / 10000.0);

    B b;
    double begin2 = base::get_elapsed_seconds();
    for (std::size_t i = 0; i < 10000; i++)
        base::get_if<A>(&b)->func();
    double end2 = base::get_elapsed_seconds();
    double delta2 = end2 - begin2;
    base::print_line("total: ", delta2, ", average: ", delta2 / 10000.0);

    base::print_line("ratio: ", delta1 / delta2);

    return 0;
}
