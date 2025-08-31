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

// Works with any callable with any number of arguments !
template <typename F, typename... Ts> // Ts is a template parameter pack - it can match any number of types
auto reallyAsync(F&& f, Ts&&... params) // params is a function parameter pack - it can accept any number of arguments
{
    return std::async(
        std::launch::async,
        std::forward<F>(f),
        std::forward<Ts>(params)... // parameter pack will get expanded
    );
}
