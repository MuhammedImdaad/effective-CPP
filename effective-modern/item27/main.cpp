#include "item.h"



int main()
{
    std::string name{"log1"};
    logging(name); //lvalue reference
    logging("log2"); //rvalue reference
    logging(10); //int index, logImpl(int idx, std::true_type) is invoked
    std::cout << std::endl;
    
    // use of Constraining templates that take universal references
    Person p1; 
    Person p2{p1};
    Person p3{std::move(p1)};
    Person p4{1};
    Person p5{1L};
    return 0;
}