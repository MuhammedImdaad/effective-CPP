#pragma once
#include <iostream>
#include <memory>

class Investment
{
public:
    virtual ~Investment() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class Equity : public Investment
{
public:
    int a1 = 10;
};

class Bond : public Investment
{
};

enum class Type
{
    Investment,
    Equity,
    Bond
};

auto createInvestment(Type type)
{
    std::unique_ptr<Investment> ptr;

    switch (type)
    {
    case Type::Bond:
        ptr.reset(new Bond);
        break;
    case Type::Equity:
        ptr.reset(new Equity);
        break;
    default:
        ptr.reset(new Investment);
    }
    return ptr;
}