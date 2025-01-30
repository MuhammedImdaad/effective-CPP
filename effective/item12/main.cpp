#include "item12.h"

int main()
{
    Derived A;
    std::cout << std::endl;

    Derived B(A); //calls copy constructor
    std::cout << std::endl;
    
    Derived C = A; //calls copy constructor
    std::cout << std::endl;
    
    C = B; //calls copy assignment
    return 0;
}