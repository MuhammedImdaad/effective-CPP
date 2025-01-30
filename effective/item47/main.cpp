#include "item47.h"
#include <list>
#include <vector>

int main()
{
    std::list<int> l;       // compile time
    std::cout << "list : "; printType<std::list<int>::iterator>();

    std::vector<int> v;       // run time
    std::cout << "vector : "; printType(v.begin());
    return 0;
}