#include <iostream>
#include <mutex>

class Lock
{
    std::mutex *ptr;

public:
    explicit Lock(std::mutex &ptr)
        : ptr(&ptr)
    {
        std::cout << "Locked the mutex\n";
        ptr.lock();
    }

    ~Lock()
    {
        std::cout << "Unlocked the mutex automatically\n";
        ptr->unlock();
    }
};