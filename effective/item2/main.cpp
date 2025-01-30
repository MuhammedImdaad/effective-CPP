#include "item2.h"

const int Game2::arraySize;

int main()
{
    Game1 g1 = Game1();
    g1.print(g1.arraySize);

    Game2 g2 = Game2();
    g2.print(&g2.arraySize);
}