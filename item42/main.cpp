#include <item42.h>
#include <vector>

int main()
{
    std::vector<int> v {10, 20, 30};
    print2nd<std::vector<int>>(v);
    copying(v.begin()+2);
    return 0;
}