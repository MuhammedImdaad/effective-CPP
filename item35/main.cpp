#include "item.h"

void learning()
{
    // 1. Threads (std::thread)
    std::thread t1(hello);  // Launch a new thread
    t1.join();  // Wait for the thread to finish

    // 2. Mutex (std::mutex)
    std::thread t2(safePrint, 2);
    std::thread t3(safePrint, 3);
    t2.join();
    t3.join();

    // 3. Condition Variables (std::condition_variable)
    std::thread t4(worker);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();  // Wake up the worker thread
    t4.join();

    // 4. Atomic Variables (std::atomic)
    std::thread t5(increment);
    std::thread t6(increment);
    t5.join();
    t6.join();
    std::cout << "Counter: " << counter << std::endl;

    // 5. Futures & Promises (std::future, std::promise)
    std::future<int> result = std::async(computeSquare, 5);
    std::cout << "Square: " << result.get() << std::endl; // Blocks until result is read   
}

int main() 
{
    // threads study
    std::future<void> f = std::async(learning);
}
