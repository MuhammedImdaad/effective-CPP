#include "item.h"

int main()
{
    func();
    FilterContainer filters;

    {
        int divisor = 5;
        filters.emplace_back([&divisor](int value)
                             {
            std::cout << value << " " << divisor << std::endl;
            return value % divisor; });
    }

    filters[0](45); // 45 5 undefined behavior

    Widget w;
    w.addFilter(filters);
    filters.back()(50); // 50 2
    w.setDivisor(10);
    filters.back()(45); // 45 10 same lambda changes!

    {
        Widget w1;
        w1.addFilter(filters);
    }

    filters.back()(100); // 100 2 undefined behavior
    return 0;
}