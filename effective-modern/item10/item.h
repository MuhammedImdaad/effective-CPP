#pragma once
#include <iostream>
#include <tuple>

enum Color
{
    black,
    white,
    red
};

enum class Color1
{
    blue,
    red,
    pink
};

using UserInfo = std::tuple<std::string, std::string, std::size_t>;

enum desc
{
    name,
    email,
    age
};