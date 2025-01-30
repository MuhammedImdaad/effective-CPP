#include "item24.h"

using namespace num;
const Rational num::Rational::operator*(const Rational &other)
{
    std::cout << "Member function\n";
    return Rational(numerator * other.numerator,
                    denominator * other.denominator);
}

const Rational num::operator*(const Rational &lhs, const Rational &rhs)
{
    std::cout << "Non member function\n";
    return Rational(lhs.getNum() * rhs.getNum(), lhs.getDen() * rhs.getDen());
}