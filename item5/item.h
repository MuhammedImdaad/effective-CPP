#pragma once
#include <iostream>
#include <memory>
#include <functional>

// usecase 2
template <typename It>
void usecase2(It b, It e)
{
    for (; b != e; ++b)
    {
        // typename std::iterator_traits<It>::value_type currValue = *b;
        auto currValue = *b;
    }
}

// usecase 3 :
auto unknownType11 = // C++11 comparison
    [](const std::unique_ptr<int> &p1,
       const std::unique_ptr<int> &p2)
{ return *p1 < *p2; }; // represent closure types known only to compilers

auto unknownType14 = // C++14 comparison (auto arguments)
    [](const auto &p1,
       const auto &p2)
{ return *p1 < *p2; };

std::function<bool(const std::unique_ptr<int> &,
                   const std::unique_ptr<int> &)>
    unknownFunc;