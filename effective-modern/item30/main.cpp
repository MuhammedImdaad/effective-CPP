#include "item.h"

// constexpr int Widget::val; // define

int main()
{
    // Braced initializers
    // func({1,2,3}); // error: no matching function for call to ‘func(<brace-enclosed initializer list>)’,
    // note:   couldn’t deduce template parameter ‘T’

    std::vector<int>(Widget::val);
    // func(Widget::val); // undefined reference to `Widget::val'

    f1(f);
    // func(f); // error: no matching function for call to ‘func(<unresolved overloaded function type>)’

    IPv4Header h;
    h.totalLength = 1000;
    std::vector<int>(h.totalLength);
    // func(h.totalLength); // taking the address of a bit field is not allowed

    return 0;
}