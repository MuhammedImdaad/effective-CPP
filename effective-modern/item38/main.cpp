#include <iostream>
#include <future>
#include <thread>

int main()
{
    auto lambda = [](int times)
    {
        using namespace std::literals;
        for (int i = 0; i < times; i++)
        {
            std::cout << i << " ";
            std::this_thread::sleep_for(10ms);
        }
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    // fut refers to the shared state that was created due to a call to std::async
    // task’s launch policy is std::launch::async
    // fut is the last future referring to the shared state
    std::future<void> fut = std::async(std::launch::async, lambda, 100); 
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // all 3 conditions satisfied. Blocks until the asynchronously running lambda completes (implicit join in the destructor)
    return 0;
}