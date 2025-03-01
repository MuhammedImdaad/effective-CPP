#pragma once
#include <vector>
#include <cstdint>

template <typename T>
void func(T &&param) {}

class Widget
{
public:
    static constexpr int val = 28;
};


void f(int) {};
void f(int, int) {};

void f1(void (*argf)(int)) {};

struct IPv4Header
{
    std::uint32_t version      : 4,
                  IHL          : 4,
                  DSCP         : 6,
                  ECN          : 2,
                  totalLength  : 16;
};