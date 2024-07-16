#include "item25.h"

int main()
{
    custom::Widget w1;
    custom::Widget w2;

    std::swap(w1, w2);
    swap(w1, w2);
    w1.swap(w2);
    return 0;
}