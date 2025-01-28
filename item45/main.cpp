#include <item45.h>

int main()
{
    Top* p1 = new Middle;
    Top* p2 = new Bottom;
    // Bottom* p3 = new Top; //won't compile
    const Top* p4 = p1;
    // Top* p5 = p4; //wont' compile

    SmartPtr<Top> p6 = SmartPtr<Middle>(new Middle);
    SmartPtr<Top> p7 = SmartPtr<Bottom>(new Bottom);
    // SmartPtr<Bottom> p8 = SmartPtr<Top>(new Top); //shouldn't compile
    const SmartPtr<Top> p9 = p6;
    SmartPtr<Top> p10 = p9; //shouldn't compile but it does :(
    return 0;
}