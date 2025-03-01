#pragma once
#include <iostream>
#include <memory>

class Widget
{
public:
    virtual void println()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~Widget() = default;
};

class SpecialWidget : public Widget
{
public:
    virtual void println() override
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~SpecialWidget() = default;
};

void print(std::unique_ptr<Widget>& w)
{
    w->println();
}