#include "item.h"

int main()
{
    WidgetA wA;
    wA.timer();
    wA.test();
    std::cout << "------------------------" << std::endl;
    WidgetB wB;
    // wB.timer();
    wB.test();
    std::cout << "------------------------" << std::endl;
    WidgetC wC;
    // wC.timer();
    wC.test();
    std::cout << "------------------------" << std::endl;
    WidgetD wD;
    // wD.timer();
    wD.test();
    std::cout << "------------------------" << std::endl;
    return 0;
}