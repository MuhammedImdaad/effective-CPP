#include "item.h"

int main()
{
    auto w1{std::make_unique<Widget>(100)};
    auto w2 = std::make_unique<Widget>(200);
    std::cout << __PRETTY_FUNCTION__ << " " << w1.get() << " " << w2.get() << std::endl;

    // closure is getting created, w2 is moved here
    auto func = [&w1 = w1, w2 = std::move(w2)]()
    {
        std::cout << __PRETTY_FUNCTION__ << " " << w1.get() << " " << w1->value << std::endl;
        std::cout << __PRETTY_FUNCTION__ << " " << w2.get() << " " << w2->value << std::endl;
    };

    std::cout << __PRETTY_FUNCTION__ << " " << w1.get() << " " << w2.get() << std::endl;
    func();
    func();
    std::cout << __PRETTY_FUNCTION__ << " " << w1.get() << " " << w2.get() << std::endl;

    /*
        int main() bbb ccc
        int main() bbb 0

        main()::<lambda()> bbb 100
        main()::<lambda()> ccc 200

        main()::<lambda()> bbb 100
        main()::<lambda()> ccc 200
        
        int main() bbb 0
    */
    return 0;
}