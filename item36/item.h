#pragma once
#include <iostream>
#include <future>
#include <thread>

using namespace std::literals;

void f(int i = 0);
void f(int i)
{
    std::cout << __PRETTY_FUNCTION__ << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(i));
}

template <typename F, typename... Ts>
auto reallyAsync(F&& f, Ts&&... params)
{
    return std::async(
        std::launch::async,
        std::forward<F>(f),
        std::forward<Ts>(params)...
    );
}
