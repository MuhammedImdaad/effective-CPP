#include "item.h"

int main()
{
    std::string name{"log1"};
    logging(name);   // lvalue reference
    logging("log2"); // rvalue reference
    logging(10);     // int index, logImpl(int idx, std::true_type) is invoked
    std::cout << std::endl;

    // use of Constraining templates that take universal references
    Person p1;
    Person p2{p1};
    Person p3{std::move(p1)};
    Person p4{1};
    Person p5{1L};
    Person p6{"p6"};

    /*
        void logging(T&&) [with T = std::__cxx11::basic_string<char>&]
        void logImpl(T&&, std::false_type) [with T = std::__cxx11::basic_string<char>&; std::false_type = std::integral_constant<bool, false>]
        LOG: log1

        void logging(T&&) [with T = const char (&)[5]]
        void logImpl(T&&, std::false_type) [with T = const char (&)[5]; std::false_type = std::integral_constant<bool, false>]
        LOG: log2

        void logging(T&&) [with T = int]
        void logging(T&&) [with T = std::__cxx11::basic_string<char>]
        void logImpl(T&&, std::false_type) [with T = std::__cxx11::basic_string<char>; std::false_type = std::integral_constant<bool, false>]
        LOG: temp
        void logImpl(int, std::true_type)

        Person::Person(const Person&)
        Person::Person(Person&&)
        Person::Person(int)
        Person::Person(int)
        Person::Person(T&&) [with T = const char (&)[3]; <template-parameter-1-2> = void]
    */
    return 0;
}