#include <string>
#include <iostream>

template <typename T>
class Object
{
public:
    Object() { std::cout << "Object created\n";}
    static void instant()
    {
        T t;
        std::cout << &t << std::endl;
    }
};

int main()
{
    //for each template, each new class representation is generated using implicit interfaces
    Object<int>::instant(); //first int class
    Object<int>::instant(); //make use of the above int class
    Object<long>::instant(); //create a new long class
    Object<int>::instant(); //make use of the same int class
    Object<std::string>::instant(); //create a new string class
    Object<std::string> o; //first object init
    // o::instant(); //won't compile
    return 0;
}