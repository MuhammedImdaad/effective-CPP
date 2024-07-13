#include <iostream>

class Base
{
public:
    Base()
    {
        log();
    }

    virtual ~Base(){};

protected:
    virtual void log() {std::cout << "Base class created\n";};
};

class Derived : public Base
{
protected:
    void log() override { std::cout << "Derived class created\n"; }
};
