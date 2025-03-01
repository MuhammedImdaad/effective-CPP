#pragma once
#include <iostream>

#include <array>

class Point
{
    double x, y;

public:
    constexpr Point(double x, double y)
        : x(x), y(y)
    {
    }

    constexpr auto getX() const { return x; }
    constexpr auto getY() const { return y; }
};

constexpr Point midPoint(const Point &p1, const Point &p2)
{
    return Point{p1.getX() / 2 + p2.getX() / 2, p2.getY() / 2 + p2.getY() / 2};
}