#include "item.h"

int main()
{
    // auto white = false; // error: ‘auto white’ redeclared as different kind of entity

    auto blue = "scoped enum";

    Color c = red;
    if (c == 2)
        std::cout << "unscoped enum implicit conversion\n";

    Color1 c1 = Color1::pink;

    if (static_cast<int>(c1) == 2)
        std::cout << "scoped enum explicit conversion\n";

    UserInfo info1;

    auto name1 = std::get<0>(info1); //need to remember name 

    auto email1 = std::get<email>(info1); // a lot easier right
}