#include <iostream>
#include <string>

class Base
{
private:
    int id;
    std::string name;

public:
    Base() { std::cout << "Base default constructor\n"; }

    Base(const Base &other)
        : id(other.id), name(other.name)
    {
        std::cout << "Base copy constructor\n";
    }

    Base &operator=(const Base &other)
    {
        std::cout << "Base copy assignment\n";
        id = other.id;
        name = other.name;
        return *this;
    }
};

class Derived : public Base
{
private:
    double price;

public:
    Derived() { std::cout << "Derived default constructor\n"; };

    Derived(const Derived &other)
        : 
        Base(other), //comment out 
        price(other.price)
    {
        std::cout << "Derived copy constructor\n";
    }

    Derived &operator=(const Derived &other)
    {
        Base::operator=(other); //comment out 
        std::cout << "Derived copy assignment\n";
        price = other.price;
        return *this;
    }
};
