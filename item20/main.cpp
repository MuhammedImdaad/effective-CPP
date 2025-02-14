#include <memory>
#include <iostream>

class Widget{};
int main()
{
    std::shared_ptr<Widget> shr (new Widget);
    std::cout << shr.use_count() << std::endl; // 1
    std::weak_ptr<Widget> weak{shr};
    auto shr2{shr};
    std::cout << shr.use_count() << std::endl; // 2 not 3
    shr2 = nullptr;
    std::cout << shr.use_count() << std::endl; // 1

    std::shared_ptr<Widget> shr3{weak.lock()};
    std::shared_ptr<Widget> shr4{weak};
    std::cout << shr.use_count() << " " << weak.expired() << " " << shr3 << std::endl; // incremented to 3 due to shr3
    shr.reset();
    std::cout << shr3.use_count() << " " << weak.expired() << " " << shr3 << std::endl; // 2
    shr3.reset(), shr4.reset();
    std::cout << shr3.use_count() << " " << weak.expired() << " " << shr3 << std::endl; // 0, weak is expired
    return 0;
}