#include "item19.h"

void print(int value)
{
    std::cout << "Printed value " << value << std::endl;
}

int main()
{
    // Implicit Conversions
    T1 t1 = 10; // Non-explicit Constructor
    print(t1); // Conversion Operator

    // Explicit Conversions
    T2 t2 = T2(20); // Explicit Constructor
    print ((int)t2); // Conversion Operator
    return 0;
}