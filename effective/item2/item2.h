#include <iostream>

class Game1
{
    public:
    static const int arraySize = 5;
    int array[arraySize];
    void print(const int size)
    {
        std::cout << "printing array " << size << std::endl;
    }
};


class Game2
{
    public:
    static const int arraySize = 25;
    int array[arraySize];
    void print(const int* size)
    {
        std::cout << "printing array " << *size << std::endl;
    }
};