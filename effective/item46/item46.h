#include <iostream>

namespace num
{
    template <typename T>
    class Rational
    {
        T numerator;
        T denominator;

    public:
        Rational(T num = 0, T den = 1) // implicit
            : numerator(num), denominator(den)
        {
        }

        friend const Rational operator*(const Rational &lhs, const Rational &rhs)
        {
            return multiply(lhs, rhs);
        };

        void print() const
        {
            std::cout << numerator << '/' << denominator << std::endl;
        }

        int getNum() const { return numerator; }
        int getDen() const { return denominator; }
    };

    template <typename T>
    const Rational<T> multiply(const Rational<T> &lhs, const Rational<T> &rhs)
    {
        return Rational<T>(lhs.getNum() * rhs.getNum(), lhs.getDen() * rhs.getDen());
    };
}