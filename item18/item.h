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
    auto customDelete = [](Investment* ptr){std::cout << __PRETTY_FUNCTION__ << std::endl; delete ptr;};
    std::unique_ptr<Investment, decltype(customDelete)> ptr(nullptr, customDelete);

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

    return ptr; // compiler automatically applies the move semantics to transfer ownership
}