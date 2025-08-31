#include <item.h>
class Widget
{
};
bool f(const Widget &w) {}; // decltype(w) is const Widget&
                            // decltype(f) is bool(const Widget&)

template <typename T> // simplified version of std::vector
class vector
{
public:
    T &operator[](int index) {};
};

int main()
{
    const int i = 0; // decltype(i) is const int

    struct Point
    {
        int x, y; // decltype(Point::x) is int
    }; // decltype(Point::y) is int

    Widget w; // decltype(w) is Widget

    if (f(w)) // decltype(f(w)) is bool
    {
    }

    vector<int> v; // decltype(v) is vector<int>
    if (v[0] == 0) // decltype(v[0]) is int&
        return 0;

    const Widget &cw = w;

    auto myWidget1 = cw; // auto type deduction:
                         // myWidget1's type is Widget

    decltype(auto) myWidget2 = cw; // decltype type deduction:
                                   // myWidget2's type is
                                   //   const Widget&
}