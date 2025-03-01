#include "Widget.h"
#include <iostream>
#include <vector>
#include <string>

class Gadget
{
};

struct Widget::Impl
{
    std::string name1;
    std::vector<double> data;
    Gadget g1, g2, g3;

    ~Impl() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

Widget::Widget()
    : pImpl{std::make_unique<Impl>()}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Widget::~Widget() = default;