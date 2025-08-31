#include <memory>
#include <iostream>

class Widget{};

int main()
{
    /* visualize with below diagram, weak pointers wouldn't affect reference count
    |`````````|
    | widget  | <---- shr1
    |_________|
    */

    std::shared_ptr<Widget> shr1 (new Widget);
    std::cout << shr1.use_count() << std::endl; // 1
    std::weak_ptr<Widget> weak{shr1};
    auto shr2{shr1};
    std::cout << shr1.use_count() << std::endl; // 2 not 3
    shr2 = nullptr;
    std::cout << shr1.use_count() << std::endl; // 1

    // shr1.reset();
    std::shared_ptr<Widget> shr3{weak.lock()}; // if week is expired, shr3 is null
    std::shared_ptr<Widget> shr4{weak}; // // if week is expired, throw std::bad_weak_ptr

    std::cout << shr1.use_count() << " " << weak.expired() << " " << shr3 << std::endl; // 3 0 incremented to 3
    shr1.reset();
    std::cout << shr3.use_count() << " " << weak.expired() << " " << shr3 << std::endl; // 2 0
    shr3.reset(), shr4.reset();
    std::cout << shr3.use_count() << " " << weak.expired() << " " << shr3 << std::endl; // 0 1 0, weak is expired
    return 0;
}