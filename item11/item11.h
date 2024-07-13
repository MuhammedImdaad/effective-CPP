#include <iostream>

class Storage
{
};

class Type
{
public:
    Type()
    : ptr(new Storage)
    {
    }

    Type &operator=(const Type &other)
    {
        std::cout << "copy assignment called - " << this << ", " << &other << std::endl;

        if (this == &other)
            std::cout << "self assignment\n";

        Storage *temp = ptr;
        ptr = new Storage(*other.ptr);

        if (ptr)
            delete temp;
        else
            ptr = temp;
        return *this;
    }

    Storage *ptr;
};