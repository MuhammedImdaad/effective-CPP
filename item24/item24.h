#include <iostream>

namespace num
{
    class Rational
    {
        int numerator;
        int denominator;

    public:
        Rational(int num = 0, int den = 1)
            : numerator(num), denominator(den) {}

        const Rational operator*(const Rational &other); //not required anymore

        void print() const
        {
            std::cout << numerator << '/' << denominator << std::endl;
        }

        int getNum() const { return numerator; }
        int getDen() const { return denominator; }
    };

    const Rational operator*(const Rational &lhs, const Rational &rhs);
}