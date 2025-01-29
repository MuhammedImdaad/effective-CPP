#include <iostream>

template <unsigned long n> // general case
struct Factorial
{
    enum
    {
        value = n * Factorial<n - 1>::value
    };
};

template <> // special case
struct Factorial<0>
{
    enum
    {
        value = 1
    };
};

unsigned long factorial(unsigned long n)
{
    return n ? n * factorial(n - 1) : 1;
}