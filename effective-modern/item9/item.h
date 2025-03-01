#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>
#include <list>

class Widget{};

template <typename T> //old
struct MyAllocListOld
{
    typedef std::list<T> type;
};

template <typename T> //new
using MyAllocList = std::list<T>;