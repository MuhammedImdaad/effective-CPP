#include <iostream>
#include <string>

class File
{
    std::string &name; // Reference

public:
    File(std::string &name)
        : name(name)
    {
    }

    File(const File &other) = delete;

    File &operator=(const File &other)
    {
        name = other.name;
        return *this;
    }

    std::string getName() { return name; }
};