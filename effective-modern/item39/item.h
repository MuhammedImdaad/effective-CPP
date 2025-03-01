#pragma once
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <future>
#include <vector>

std::mutex m;
std::condition_variable cv;
using namespace std::literals;

void detectOld()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::this_thread::sleep_for(2s);
    cv.notify_one();
}

void detect()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::this_thread::sleep_for(2s);
}

void reactOld()
{
    // std::this_thread::sleep_for(3s); // to show hung issue
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock); // if detectOld() notifies before react() reach cv, cv will miss the notification and will wait forever!
                   // cv is susceptible for spurious wakeups
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void react(int i = 0)
{
    std::this_thread::sleep_for(1s);
    std::cout << __PRETTY_FUNCTION__ << i << std::endl;
}

void usingCV()
{
    std::thread t(reactOld);
    detectOld();
    t.join();
}

void usingFutSingleReact()
{
    std::promise<void> p;

    std::thread t([&p]
                  {
        p.get_future().wait();
        react(); });

    detect();
    p.set_value();
    t.join();
}

void usingFutMultiReact(int reacts)
{
    std::promise<void> p;
    std::shared_future<void> sharedFut = p.get_future().share();
    std::vector<std::thread> reactors;

    for (int i = 0; i < reacts; i++)
    {
        reactors.push_back(std::thread{[sharedFut, i]
                                         {
                                             sharedFut.wait();
                                             react(i+1);
                                         }});
    }

    detect();
    p.set_value();

    for (auto& fut : reactors)
    {
        fut.join();
    }
}
