#include "item.h"

int main()
{
    auto fut1 = std::async(f, 1);
    auto fut2 = std::async(std::launch::async, f, 2);

    /* if f is deferred, fut.wait_for will always return std::future_status::deferred.
    This kind of bug is easy to overlook during development and unit testing, 
    because it may manifest itself only under heavy loads. 
    if the hardware isn’t threatened by oversubscription or thread exhaustion, 
    there’s no reason for the runtime system not to schedule the task for concurrent execution (async). */

    while (fut1.wait_for(100ms) != std::future_status::ready)
        ; // may never terminate!
    while (fut2.wait_for(100ms) != std::future_status::ready)
        ; // will always terminate

    auto fut3 = reallyAsync(f, 3);
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return 0;
}