#pragma once
#include <iostream>
#include <boost/type_index.hpp>

class Widget{};

template <typename T>
void func(T&& param)
{
    std::cout << "T = "
    << boost::typeindex::type_id_with_cvr<T>().pretty_name()
    << ", \t";

    std::cout << "param = "
    << boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name()
    << '\n';
}