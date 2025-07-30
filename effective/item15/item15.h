#include <iostream>

class Integer
{
    int value;

public:
    Integer(int value)
        : value(value)
    {
    }

    explicit operator int() const
    {
        return value;
    } 

    operator float() const
    {
        return (float)value;
    }
};