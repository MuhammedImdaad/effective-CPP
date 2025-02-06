#include "item.h"

int main()
{
    typedef std::unique_ptr<std::unordered_map<std::string, std::string>> //old
        UPtrMapSS;

    using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>; //new

    typedef void (*func)(int, std::string &); //old
    using func = void (*)(int, std::string &); //new

    MyAllocListOld<Widget>::type lw; //old
    MyAllocList<Widget> lww; //new
    return 0;
}