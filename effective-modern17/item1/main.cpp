#include <map>
#include <string>
#include <iostream>
#include <vector>

std::tuple<int, int> dividing(int num, int den) 
{
    return {num / den, num % den};
}

struct Point
{
    int px;
    int py;
};

int main()
{
    // array
    // std::vector<int> values {1, 2, 3}; // error: 3 names provided while ‘std::vector<int>’ decomposes into 1
    std::array<int, 3> values {1, 2, 3};
    auto[x, y, z] = values;
    std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;

    // map
    std::map<std::string, int> counts = {
        {"mango", 3},
        {"orange", 10}
    };

    for (auto& [fruit, count] : counts) {
        std::cout << fruit << " - " << count << std::endl; // {const std::string &, int &}
    };

    // Tuple
    auto [div, rem] = dividing(17, 5);
    std::cout << div << " - " << rem << std::endl;

    // struct
    const Point p{4, 7};
    auto& [px, py] = p;
    std::cout << "Point: (" << px << ", " << py << ")\n";

    return 0;
}