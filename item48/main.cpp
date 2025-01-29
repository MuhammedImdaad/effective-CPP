#include <item48.h>

int main()
{
    std::cout << Factorial<5>::value << std::endl; //compile
    std::cout << Factorial<20>::value << std::endl; //compile
    std::cout << factorial(20) << std::endl; //runtime
    return 0;
}