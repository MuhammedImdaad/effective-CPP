#include <string>
#include <iostream>

class Book
{
public:
    Book(const std::string content)
        : content(content)
    {
    }

    const char& operator[](const std::size_t pos)
    {
        std::cout << "operator[] called\n";
        return content[pos];
    }

    const char& operator[](const std::size_t pos) const // const object can only use const methods
    {
        std::cout << "const operator[] called\n";
        return content[pos];
    }

private:
    std::string content;
};
