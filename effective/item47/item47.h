#include <iostream>

template <typename IterT>
void helper()
{
    std::cout << "unknown\n";
}

template <>
void helper<std::bidirectional_iterator_tag>()
{
    std::cout << "bidirectional\n";
}

template <>
void helper<std::random_access_iterator_tag>()
{
    std::cout << "random access\n";
}

template <typename IterT>
void printType()
{
    //compile time
    helper<typename std::iterator_traits<IterT>::iterator_category>();
}

template <typename IterT>
void printType(IterT itr)
{
    // run time
    if (typeid(typename std::iterator_traits<IterT>::iterator_category) == typeid(std::bidirectional_iterator_tag))
        std::cout << "bidirectional\n";
    if (typeid(typename std::iterator_traits<IterT>::iterator_category) == typeid(std::random_access_iterator_tag))
        std::cout << "random access\n"; 
}