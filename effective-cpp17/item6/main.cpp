#include <iostream>
#include <variant>

int main()
{
    std::variant<int, short, float> number;
    number = 6;

    //super type safety union, not even int, float get mixed
    try {
        std::cout << std::get<float>(number);
    }
    catch (std::bad_variant_access)
    {
        std::cout << "its not a float\n";
    }

    if (std::get_if<short>(&number) == nullptr)
        std::cout << "its not short either\n";

    number = 6.f;

    auto decimal = std::get_if<float>(&number);
    if (decimal)
        std::cout << "now it is float - " << *decimal << std::endl;
    return 0;
}