#include "item.h"

int main()
{
    typedef std::unique_ptr<std::unordered_map<std::string, std::string>> //old
        UPtrMapSS1;

    using UPtrMapSS2 = std::unique_ptr<std::unordered_map<std::string, std::string>>; //new

    // reason 1
    typedef void (*func)(int, std::string &); //old
    using func = void (*)(int, std::string &); //new

    // reason 2
    MyAllocListOld<Widget>::type lw; //old
    MyAllocList<Widget> lww; //new
    
    return 0;
}