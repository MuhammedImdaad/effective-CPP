#include <iostream>

template <typename T>
void processing(T &&input)
{
    if constexpr (std::is_integral_v<std::decay_t<T>>)
        std::cout << "processing integer - " << input << std::endl;
    else if constexpr (std::is_floating_point_v<std::decay_t<T>>)
        std::cout << "processing floating - " << input << std::endl;
    else if constexpr (std::is_same_v<std::decay_t<T>, std::string>)
        std::cout << "processing string of length - " << input.size() << std::endl;
    else
        std::cout << "unhandled type\n";
}

template <typename T>
constexpr T gcd(T a, T b)
{
    if constexpr (std::is_integral_v<T>)
    {
        while (b != 0)
        {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    else
    {
        static_assert(std::is_integral_v<T>, "GCD only works with integral types");
    }
}

int main()
{
    processing(1);
    processing(1.01);
    processing(std::string("2.0000"));
    processing("2000");

    std::cout << "gcd(48, 18) = " << gcd(48, 18) << "\n";
    // std::cout << "gcd(48.0, 18.0) = " << gcd(48.0, 18.0) << "\n"; // error: static assertion failed: GCD only works with integral types

    return 0;
}