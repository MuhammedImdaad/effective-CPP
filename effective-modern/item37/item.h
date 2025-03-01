#pragma once
#include <iostream>
#include <vector>
#include <thread>

class ThreadRAII
{
public:
    enum class DtorAction
    {
        join,
        detach
    };

    ThreadRAII(std::thread t, DtorAction d)
        : action{d}, t{std::move(t)} // std::thread objects aren’t copyable
    {
    }

    ThreadRAII(ThreadRAII &&other) = default;
    ThreadRAII &operator=(ThreadRAII &&other) = default;

    auto &get() { return t; }

    ~ThreadRAII()
    {
        std::cout << (t.joinable() ? "t is joinable\n" : "t is unjoinable\n");
        std::cout << "dtor action for joinable thread is " << (action == DtorAction::join ? "join \n" : "detach\n");
        if (t.joinable())
        {
            if (action == DtorAction::join)
                t.join();
            else
                t.detach();
        }
        else
        {
            // invoking join or detach on an unjoinable thread yields undefined behavior
        }
    }

private:
    std::thread t;
    DtorAction action;
};

bool conditionsAreSatisfied();
void performComputation(std::vector<int> &) noexcept {};

bool doWorkBad(int limit)
{
    using namespace std::literals;
    std::vector<int> result;

    std::thread t([&result, limit]()
                  {
        for (int i = 0; i < limit; i++)
        {result.push_back(i);
            std::this_thread::sleep_for(1ms); } });

    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << (t.joinable() ? "t is joinable\n" : "t is unjoinable\n") << std::endl;

    if (conditionsAreSatisfied())
    {
        t.join();
        performComputation(result);
        return true;
    }

    return false; // terminate called without an active exception \n Aborted (core dumped)
}

bool doWorkGood(int limit, ThreadRAII::DtorAction actionOnExit)
{
    using namespace std::literals;
    std::vector<int> result;

    ThreadRAII t {
        std::thread {
            [&result, limit]()
            {
                for (int i = 0; i < limit; i++)
                {
                    result.push_back(i);
                    std::this_thread::sleep_for(1ms);
                }
            }
    },
    actionOnExit
    };

    if (conditionsAreSatisfied())
    {
        t.get().join();
        performComputation(result);
        return true;
    }

    return false; // ~ThreadRAII is called
}