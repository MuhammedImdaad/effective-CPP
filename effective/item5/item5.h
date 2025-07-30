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
        // copies the contents of the string referenced by 
        // other.name into the string referenced by name. 
        // It does not change what name refers to.
        name = other.name;
        return *this;
    }

    std::string getName() { return name; }
};