#pragma once
#include <memory>

class Widget
{
public:
    Widget();
    ~Widget(); // declaration only

    // if destructor was not defined this is what the compiler would do (Inline destructor)
    //  ~Widget() = default; // error: invalid application of ‘sizeof’ to incomplete type ‘Widget::Impl’

private:
    struct Impl;                 // forward declared
    std::unique_ptr<Impl> pImpl; // pImpl is incomplete
};