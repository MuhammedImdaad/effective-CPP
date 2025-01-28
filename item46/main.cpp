#include "item46.h"

int main()
{
    num::Rational<int> num1(1,2);
    num::Rational<int> num2(3,5);

    num::Rational<int> result1 = num1 * num2;
    result1.print();
    num::Rational<int> result2 = num2 * 4;
    result2.print();
    num::Rational<int> result3 = 2 * num2;
    result3.print();
    num::Rational<int> result4 = 2 * 7;
    result4.print();
    return 0;
}