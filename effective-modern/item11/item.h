#pragma once
#include <iostream>

class A
{
public:
    A() {};
    A &operator=(const A &other) = delete; // C11
private:
    A(const A &other); // C98
};

bool isLucky(int) { return true; }
bool isLucky(char) = delete;
bool isLucky(double) = delete;
bool isLucky(bool) = delete;

template <typename T>
void func(T* ptr){}

template <>
void func<void>(void* ptr) = delete;