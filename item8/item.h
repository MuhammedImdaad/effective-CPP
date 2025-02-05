#pragma once
#include <iostream>

#include <memory>

class Widget
{
};

void f1(std::shared_ptr<Widget> spw) {};    // call these only when
void f2(std::unique_ptr<Widget> upw) {}; // the appropriate
void f3(Widget *pw) {};                    // mutex is locked

template <typename FuncType,
          typename PtrType>
void f(FuncType func, PtrType ptr)
{
    func(ptr);
}
