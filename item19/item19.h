#include <iostream>

class T1
{
    int value;

public:
    T1(int value) : value(value) {}

    operator int() const
    {
        return value;
    }
    
};

class T2
{
    int value;

public:
    explicit T2(int value) : value(value) {}

    explicit operator int() const
    {
        return value;
    }
};