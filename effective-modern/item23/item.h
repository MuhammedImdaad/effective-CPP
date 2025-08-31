#pragma once
#include <iostream>

class Widget
{
public:
    Widget() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Widget() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    Widget(const Widget &other) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Widget &operator=(const Widget &other) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }

    Widget(Widget &&other) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Widget &operator=(Widget &&other) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
};

void process(const Widget &params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void process(Widget &&params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <typename T>
void logAndProcess(T &&params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    // process(params);
    process(std::forward<T>(params));
}

void processLvalue(Widget &params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void processRvalue(Widget &&params)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}