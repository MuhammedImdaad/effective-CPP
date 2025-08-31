#pragma once
#include <iostream>

#include <memory>

class Widget
{
};

void f1(std::shared_ptr<Widget> spw) {};
void f2(std::unique_ptr<Widget> upw) {};
void f3(Widget *pw) {};

template <typename FuncType,
          typename PtrType>
void f(FuncType func, PtrType ptr)
{
    func(ptr);
}
