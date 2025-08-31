#include "item.h"

int main()
{
    double x(0.0);  // initializer is in parentheses
    double y = 0.0; // initializer follows "="
    double z{0.0};  // initializer is in braces

    int sum1{x + y + z}; // warning: narrowing conversion of ‘((x + y) + z)’ from ‘double’ to ‘int’

    // most vexing parse
    A a1; // object / variable
    a1.func();
    A a2(); // warning: empty parentheses were disambiguated as a "function declaration"
    // a2.func(); // error: expression must have class type but it has type "A (*)()"
    A a3{}; // calls Widget ctor with no args; Empty braces mean no arguments, not an empty std::initializer_list
    a3.func();

    Widget w1 (10, true); // calls first ctor
    Widget w2 (10, 5.0);  // calls second ctor
    Widget w3 {10, true}; // also calls first ctor
    Widget w4 {10, 5.0};  // also calls second ctor
}