#include <iostream>
#include <vector>

template <typename T>
void f(T param) {};

/*auto createInitList() // c++14
{
    return {1, 2, 3};   // error: can't deduce type
}*/

int main()
{
    // part 1 - initialize using brackets
    auto x1 = 27;
    auto x2(27);

    // part 2 - initialize using braces
    auto x4{27};                // int
    auto x3 = {27};             // std::initializer_list<int> -------------------
    auto x = {11, 23, 9};       // x's type is std::initializer_list<int>
    // auto x5 = {1, 2, 3.0};   // error! can't deduce T for

    // part 3 - template deduction
    //  f({11, 23, 9});         // error! can't deduce type for T -> std::initializer_list<T> for template deduction

    // part 4 - function & lamba deduction
    std::vector<int> v = {4, 5, 6};
    /// c++14
    // Takes any type as a const reference, Captures v by reference, Assigns newValue to v and Lambda assigned to a variable.
    auto resetV = [&v](const auto &newValue)
    { v = newValue; };

    // resetV(createInitList());        // can't deduce type for return of initializer list
    // resetV({1, 2, 3});               // can't deduce type for parameter of initializer list
    resetV(std::vector<int>{1, 2, 3});  // can
    for (int i : v)
        std::cout << i << " ";
}