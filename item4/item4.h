#include <iostream>
#include <string>

class File
{
    std::string localStr;
public:
    File(){std::cout << "Default constructor\n";}
    File(const std::string& str){ localStr = str; std::cout << "Custom constructor\n";}
    File(const File& other) { localStr = other.localStr; std::cout << "Copy constructor\n";}
    
    File& operator=(const File& other) {localStr = other.localStr; std::cout << "copy assignment\n"; return *this;} 
};

class System
{
    File file1; // only Copy constructor
    File file2; // Default constructor followed by copy assignment

    //following can only be intialized using an initialization list
    const int file1ID;
    int& file2ID;

public:
    System(const File& file, int id1, int& id2)
        : file1(file), file1ID(1), file2ID(id2)
    {
        file2 = file;
    }
};