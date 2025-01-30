#include "item14.h"

int main()
{
    std::mutex m;

    {
        Lock l(m);
        // do something
    }
    return 0;
}