#include <iostream>

void setDates(int month, int day, int year);

enum class Month
{
    jan,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

struct Day
{
    Day(int day)
        : day(day) {}
    int day;
};

struct Year
{
    Year(int year) : year(year) {}
    int year;
};

void setDates(enum Month, Day, Year);