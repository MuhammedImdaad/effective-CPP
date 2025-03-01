#include "item.h"

int main()
{
    Widget w;
    func(w); // T = Widget&
    func(std::move(w)); // T = Widget
    int x;
    // auto& & rx = x; // error! can't declare reference to reference

    auto&& w1 = w; // Widget &w1
    auto&& w2 = std::move(w); // Widget &&w2
    return 0;
}