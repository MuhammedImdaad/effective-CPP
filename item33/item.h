#include <iostream>

class Base
{
public:
    virtual void f1() = 0;
    virtual void f1(int x) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    virtual void f2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void f3() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void f3(int) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Derived : public Base
{
public:
    using Base::f1;
    virtual void f1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    using Base::f3;
    void f3(int) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};