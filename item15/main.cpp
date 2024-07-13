#include "item15.h"

void printI(int num)
{
    std::cout << "printed " << num << std::endl;
}

void printD(double num)
{
    std::cout << "printed " << num << std::endl;
}

void printF(float num)
{
    std::cout << "printed " << num << std::endl;
}

int main()
{
    Integer i(10);

    // printD(i); //without conversion operator, compile error
    printI((int)i); //with explicit conversion operator
    printF(i); //with implicit conversion operator
    
    return 0;
}