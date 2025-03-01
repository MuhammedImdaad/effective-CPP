#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> names;
    names.push_back("joe"); // string literal, a sequence of characters inside quotes. string literal is not a std::string 
    names.emplace_back("rogan");
    names.emplace_back(10, 'x');
    names.push_back(std::string(10, 'y'));
    // names.push_back(std::string(10, 'z')); // error: no matching function for call

    for (auto& name : names)
        std::cout << name << std::endl;

    return 0;
}