#include "item.h"

int main()
{
    Widget w;
    
    logAndProcess(w); //lvalue
    logAndProcess(std::move(w)); //rvalue
    logAndProcess(Widget{}); //rvalue
    return 0;
}