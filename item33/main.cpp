#include <iostream>
#include <item.h>
int x = 10;

int main()
{
    {
        double x = 15.89;
        std::cout << x << std::endl;
    }

    Derived d;
    d.f1();
    d.f1(5);
    d.f2();
    d.f3();
    d.f3(5);

    return 0;
}