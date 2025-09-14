#include <iostream>
#include <fstream>
#include <optional>

std::optional<std::string> readFile(const std::string &filePath)
{
    // readfile
    std::ifstream stream(filePath);
    if (stream)
    {
        return "result";
    }

    return {}; // implicit conversion to std::optional
}
int main()
{
    auto content = readFile("../file1.txt");
    if (content)
    {
        std::cout << "read successfull - " << content.value() << std::endl;
    }
    else
    {
        // Using value_or for default values
        std::cout << "read failed - " << content.value_or("0") << std::endl;
    }
    return 0;
}