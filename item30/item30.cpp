#include "item30.h"

Custom::Custom(int age)
    : age(age)
{
}

int Custom::getAgeLow()
{
    return age - 2;
}

int someAge()
{
    return 11;
}