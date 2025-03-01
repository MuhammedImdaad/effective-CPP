#pragma once
#include <iostream>

class Widget
{
public:
    /*Widget::Widget(int, bool)
    Widget::Widget(int, double)
    Widget::Widget(int, bool)
    Widget::Widget(int, double)*/
    Widget(int i, bool b) { std::cout << __PRETTY_FUNCTION__ << std::endl; }; // ctors not declaring
    Widget(int i, double d) { std::cout << __PRETTY_FUNCTION__ << std::endl; };

    /*Widget::Widget(int, bool)
    Widget::Widget(int, double)
    Widget::Widget(std::initializer_list<double>)
    Widget::Widget(std::initializer_list<double>)*/
    Widget(std::initializer_list<double> il) { std::cout << __PRETTY_FUNCTION__ << std::endl; };  // std::initializer_list params

    // error: narrowing conversion of ‘10’ from ‘int’ to ‘bool’
    // Widget(std::initializer_list<bool> il) { std::cout << __PRETTY_FUNCTION__ << std::endl; }; // element type is now bool

    /*Widget::Widget(int, bool)
    Widget::Widget(int, double)
    Widget::Widget(int, bool)
    Widget::Widget(int, double)*/
    // Widget(std::initializer_list<std::string> il) { std::cout << __PRETTY_FUNCTION__ << std::endl; }; // std::initializer_list params

private:
    int x{0};  // fine, x's default value is 0
    int y = 0; // also fine
    // int z(1);  // error: expected identifier before numeric constant
};

struct A
{
    void func() {}
};