#include <iostream>
#include <map>

void ifinit()
{
    if (short k = 578; k != 578)
    {
        std::cout << k << "K not found" << std::endl;
    }
    else
    {
        std::cout << k << "K found" << std::endl;
    }
    
    std::map<std::string, int> students{
        {"alice", 10},
        {"bruce", 15}};

    if (auto it = students.find("alice"); it != students.end())
    {
        auto [name, score] = *it;
        std::cout << "Alice's score: " << score << "\n";
    }
    else
    {
        std::cout << "Alice not found" << &it << "\n";
    }
}

int main()
{
    ifinit();
    return 0;
}