#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
std::atomic<int> counter(0);

void hello() {
    std::cout << "Hello from thread!" << std::endl;
}

void safePrint(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " is running\n";
}

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });  // Wait until `ready` is true
    std::cout << "Worker thread running\n";
}

void increment() {
    for (int i = 0; i < 1000; ++i)
        counter++;
}

int computeSquare(int x) {
    return x * x;
}