#include "item5.h"
#include <iostream>

int main()
{
    std::string fileName1 = "abc.txt";
    std::string fileName2 = "def.txt";

    File file1(fileName1);
    File file2(fileName2);

    // File file3(file1); //compile error
    
    std::cout << file1.getName() << std::endl;
    std::cout << file2.getName() << std::endl;
    file1 = file2;
    std::cout << file1.getName() << std::endl;
    std::cout << file1.getName() << std::endl;

    // you're changing the content of the string that name refers to.
    // However, file1 and file2 still hold references to their respective original strings.
    // This is not valid and hence operator should be deleted
    std::cout << fileName1 << std::endl;
    std::cout << fileName2 << std::endl;

    return 0;
}