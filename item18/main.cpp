#include "item.h"

int main()
{
    auto e1 = createInvestment(Type::Equity);
    // auto e2 = e1; //it is a deleted function
    auto e3 = std::move(e1);
    std::cout << dynamic_cast<Equity*>(e3.get())->a1 << std::endl;
    return 0;
}