#include "item.h"

int main()
{
    auto null = nullptr; //std::nullptr_t null

    f1(0);
    f2(NULL);
    f3(nullptr);

    // f(f1, 0); // error: could not convert ‘ptr’ from ‘int’ to ‘std::shared_ptr<Widget>’
    // f(f2, NULL); // error: could not convert ‘ptr’ from ‘long int’ to ‘std::unique_ptr<Widget>’
    f(f3, nullptr);
    return 0;
}