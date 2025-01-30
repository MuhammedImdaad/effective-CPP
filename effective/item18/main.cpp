#include "item18.h"

void setDates(int month, int day, int year){}
void setDates(enum Month, Day, Year){};

int main()
{
    setDates(30, 12, 1999); //client can do major mistakes
    
    setDates(Month::dec, Day(30), Year(1999)); //hard to use incorrectly
    std::cout << "success\n";
    return 0;
}