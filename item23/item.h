#pragma once
#include <iostream>

class Widget{};

void process(const Widget& params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void process(Widget&& params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <typename T>
void logAndProcess(T&& params)
{
    // process(params);
    process(std::forward<T>(params));
}
