#include <new>
#include <item49.h>

void handler()
{
    std::cerr << __PRETTY_FUNCTION__ << " Memory allocation failed, terminating\n";
    std::abort();
}

int main()
{
    std::set_new_handler(handler); //global NH

    X::set_new_handler(X::outOfMem); //X specific NH
    // X* x = new X;

    // Y::set_new_handler(Y::outOfMem);
    Y* y = new Y; //if not set for Y, global NH
}