#include "item24.h"

int main()
{
    num::Rational num1(1,2);
    num::Rational num2(3,5);

    num::Rational result1 = num1 * num2;
    result1.print();
    num::Rational result2 = num2 * 4;
    result2.print();
    num::Rational result3 = 2 * num2;
    result3.print();
    return 0;
}