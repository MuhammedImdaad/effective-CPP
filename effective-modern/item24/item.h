#pragma once
#include <iostream>

class Widget
{
};

template <typename T>
void func(T &&param)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void onlyRvlaue(Widget &&w)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
