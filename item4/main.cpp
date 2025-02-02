#include <vector>
#include "item.h"

class Widget{};
int main()
{
    const int theAnswer = 42;

    // IDE
    auto x = theAnswer;
    auto y = &theAnswer;

    // Compiler
    //  TD<decltype(x)> xType; // elicit errors containing
    //  TD<decltype(y)> yType; // x's and y's types

    //runtime
    std::cout << typeid(x).name() << '\n'; // display types for
    std::cout << typeid(y).name() << '\n'; // x and y

    //more complicated
    const auto vw = std::vector<Widget>{1};
    // TD<decltype(&vw[0])> vType; //aggregate ‘TD<const Widget*> vType’ has incomplete type and cannot be defined
    f(vw[0]); //runtime - const reference to widget
    f(&vw[0]); //runtime - const reference to const widget pointer
}