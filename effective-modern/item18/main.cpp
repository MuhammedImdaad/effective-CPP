#include "item.h"

int main()
{
    createInvestment(Type::Bond);
    auto e1 = createInvestment(Type::Equity);
    // auto e2 = e1; //it is a deleted function
    auto e3 = std::move(e1);
    std::cout << dynamic_cast<Equity *>(e3.get())->a1 << std::endl; // with a virtual encapsulation this could be avoided
    std::shared_ptr<Investment> e4 = std::move(e3);
    return 0;
}