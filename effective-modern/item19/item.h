#pragma once
#include <memory>
#include <iostream>

class Widget
{
public:
    virtual ~Widget() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

auto createWidget()
{
    std::shared_ptr<Widget> ptr(new Widget);
    return ptr;
}