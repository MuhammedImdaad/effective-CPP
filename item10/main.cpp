#include "item10.h"

int main()
{
    Type a, b, c;
    a = b = c;

    // Here, 15 is assigned to z, then the result of that assignment (the updated z) is assigned to y,
    // then the result of that assignment (the updated y) is assigned to x.
    // The way this is implemented is that assignment returns a reference to its left-hand argument.
    return 0;
}