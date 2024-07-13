#include <iostream>

class Type
{
public:
    Type& operator=(const Type& other)
    {
        std::cout << "copy assignment called\n";
        return *this;
    }
};