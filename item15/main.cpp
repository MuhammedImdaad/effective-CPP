#include "item.h"

int main()
{
    auto x1 = 10;
    // std::array<int, x1> v1; // error: the value of ‘x1’ is not usable in a constant expression

    const auto x2 = 10;
    std::array<int, x2> v2;
    // x2 = 20; // error: assignment of read-only variable ‘x2’

    constexpr auto x3 = 10;
    std::array<int, x3> v3;
    // x3 = 20; // error: assignment of read-only variable ‘x3’

    const auto x4 = x1;
    // constexpr auto x5 = x1; // error: the value of ‘x1’ is not usable in a constant expression
    
    constexpr Point p1(9.4, 27.7);
    constexpr Point p2(28.8, 5.3);

    constexpr auto mid = midPoint(p1, p2);
    std::cout << mid.getX() << ", " << mid.getY() << std::endl;
    return 0;
}