#include "item.h"

int main()
{
    auto &&var1 = Widget{};   // rvalue reference
    auto &&var2 = var1;       // lvalue reference
    Widget &&var3 = Widget{}; // rvalue referenc
    // Widget &&var4 = var1; // error: cannot bind rvalue reference of type ‘Widget&&’ to lvalue of type ‘Widget’
    // const auto &&var5 = var1; // error: cannot bind rvalue reference of type ‘const Widget&&’ to lvalue of type ‘Widget’

    Widget w;
    func(w); // void func(T&&) [with T = Widget&]
    func(std::move(w)); // void func(T&&) [with T = Widget]

    onlyRvlaue(std::move(w)); // void onlyRvlaue(Widget&&)
    // onlyRvlaue(w);    //error: same as above
    return 0;
}