#pragma once
#include <string>
#include <iostream>

std::string getName(int idx) { return "temp"; }
template <typename T>
void logging(T &&name);

template <typename T>
void logImpl(T &&name, std::false_type)
{
    // log
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "LOG: " << name << std::endl;
}

void logImpl(int idx, std::true_type)
{
    logging(getName(idx));
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <typename T>
void logging(T &&name)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    logImpl(std::forward<T>(name), std::is_integral<std::remove_reference_t<T>>());
}

class Person
{
public:
    // templated constructor that uses SFINAE (Substitution Failure Is Not An Error) via std::enable_if_t to restrict which types 
    // can be used to construct a Person object.
    template <typename T, // can accept any type
                typename = std::enable_if_t< // enables or disables the constructor based on specific conditions
                    !std::is_base_of< // Prevents unintended conversions from derived classes
                        Person, std::decay_t<T> //strip reference const volatile specifications
                    >::value
                    && 
                    !std::is_integral< // Prevents implicit conversions from integers
                        std::remove_reference_t<T>
                    >::value
                >
            >
    explicit Person(T &&args)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Person(const Person &other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    Person(Person &&other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    explicit Person(int idx)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    Person() = default;
};