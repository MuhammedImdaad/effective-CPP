#include "item.h"

bool conditionsAreSatisfied() { return false; }
int main()
{
    // doWorkBad(3'000);
    doWorkGood(3'000, ThreadRAII::DtorAction::join);
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return 0;
}