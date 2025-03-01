#include "item.h"

int main()
{
    A a1;
    A a2;
    // A a3(a1); // error: ‘A::A(const A&)’ is private within this context
    // a2 = a1; // error: use of deleted function ‘A& A::operator=(const A&)’

    isLucky(7);
    // isLucky('a');
    // isLucky(3.5);
    // isLucky(false);

    int a = 1;
    func(&a);
    // func(static_cast<void*>(&a)); // error: use of deleted function ‘void func(T*) [with T = void]’
    return 0;
}