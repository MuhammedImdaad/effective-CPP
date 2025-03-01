#include "item.h"

// Example includes how smart pointers still perfectly work for polymorphism, not much related to the item though!
int main()
{
    auto w = std::make_unique<Widget>();
    w->println();

    std::unique_ptr<Widget> sw1 = std::make_unique<SpecialWidget>();
    sw1->println();
    auto sw2 = static_cast<decltype(w)>(std::make_unique<SpecialWidget>());
    sw2->println();

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    print(w);
    print(sw1);
    print(sw2);
    return 0;
}