#pragma once
#include <iostream>
#include <vector>
#include <functional>

auto func = [](int arg = 5)
{ std::cout << __PRETTY_FUNCTION__ << arg << std::endl; };

using FilterContainer = std::vector<std::function<bool(int)>>;

class Widget
{
public:
    void addFilter(FilterContainer &filters) const
    {
        // int localdivisor = divisor; // one solution to capture by value
        filters.emplace_back(
            // this
            [=](int value)

            {std::cout << value << " " << divisor << std::endl; return value % divisor == 0; }); // divisor is not a local variable
    }
    void setDivisor(int div) { divisor = div; }

private:
    int divisor = 2;
};