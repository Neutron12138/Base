#include <iostream>
#include "../base/base.hpp"

class Base : public base::ReferenceObject
{
public:
    Base() = default;

public:
    virtual void print()
    {
        std::cout << "Base print" << std::endl;
    }
};

class Derived : public Base
{
public:
    void print() override
    {
        std::cout << "Derived print" << std::endl;
    }

    void print2()
    {
        std::cout << "Derived print2" << std::endl;
    }
};

class ClassA
{
};

int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
    // p->as<ClassA>();
    std::cout << p->is<Derived>() << std::endl;
    p->print();
    p->as<Derived>()->print2();

    return 0;
}
