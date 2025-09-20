#include <iostream>
#include <optional>

void *operator new(size_t size)
{
    std::cout << "allocated - " << size << std::endl;
    return malloc(size);
}

void efficiency()

{
    std::string parent = "The quick brown fox";
    constexpr int index = 16;
    std::string child1 = parent.substr(0, index);

    std::string_view child2{parent.substr(0, index)}; // extremely wrong!!(new allocation, dangling view)
    std::string_view child3{parent.data(), index}; // no allocation
    std::string_view child4{std::string_view(parent).substr(0, index)}; // no allocation

    parent[0] = 't';
    std::cout << parent << '\n' << child1 << '\n'
    << child2 << '\n' << child3 << '\n' <<
    child4 << std::endl;

    // std::string newParent{child3}; 
}

std::string_view danglingView()
{
    std::string temp = "effective-CPP/effective-modern17/item4/build$";
    return temp; // implicit conversion to view and dangles
}

std::optional<std::string_view> getFileExtension(std::string_view file)
{
    auto id = file.find_last_of('.');
    if (id == std::string_view::npos)
        return {};

    return file.substr(id + 1);
}
int main()
{
    efficiency();
    std::cout << danglingView() << std::endl;

    std::string filename = "document.txt";
    auto extension = getFileExtension(filename);
    if (extension)
        std::cout << "File extension: " << *extension << "\n";
    return 0;
}