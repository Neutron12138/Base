#include <iostream>
#include "../base/base.hpp"

struct A
{
    int val = 0;
    void output() { std::cout << "val: " << val << std::endl; }
    void set(int v) { val = v; }
    int get() const { return val; }
};

int val = 0;
void output() { std::cout << "val: " << val << std::endl; }
void set(int v) { val = v; }
int get() { return val; }

int main()
{
    base::MemberField<int, A> A_val(&A::val);
    base::MemberMethod<void, A> A_output(&A::output);
    base::MemberMethod<void, A, int> A_set(&A::set);
    base::MemberMethod<int, A> A_get(&A::get);
    A a;
    A_val.set(&a, 114);
    A_output.invoke(&a, std::make_tuple());
    A_set.invoke(&a, std::make_tuple(123));
    std::cout << std::any_cast<int>(A_get.invoke(&a, std::make_tuple())) << std::endl;

    base::Field<int> _val(&val);
    base::Method<void> _output(&output);
    base::Method<void, int> _set(&set);
    base::Method<int> _get(&get);
    _val.set(nullptr, 114);
    _output.invoke(nullptr, std::make_tuple());
    _set.invoke(nullptr, std::make_tuple(123));
    std::cout << std::any_cast<int>(_get.invoke(nullptr, std::make_tuple())) << std::endl;

    return 0;
}
