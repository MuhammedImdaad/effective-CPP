#include "item.h"
#include <boost/type_index.hpp>
#include <iostream>

#include <vector>
#include <unordered_map>

using boost::typeindex::type_id_with_cvr;
int main()
{
    // usecase 1
    int x1; // potentially uninitialized
    // auto x2; // error! cannot deduce 'auto' type (initializer required)
    auto x3 = 0; // fine, x3's value is well-defined

    // usecase 4
    // The official return type of v.size() is std::vector<int>::size_type, but few developers are aware of that.
    std::vector<double> v;
    int size98 = v.size();
    auto size11 = v.size();

    // usecase 5
    std::unordered_map<std::string, int> m{{"hi", 1}};
    
    // invalid initialization of reference of type ‘std::pair<std::__cxx11::basic_string<char>, int>&
    for (const std::pair<std::string, int> &p : m)
    {
        // repeating a temporary object of the type that p wants to bind to by copying each object in m, 
        // then binding the reference p to that temporary object. At the end of each loop iteration, 
        // the temporary object will be destroyed
        
        // p.second = 2;
    }

    for (auto &p : m) // const std::pair<const std::string, int> &p
    {
    }

    std::cout << "type of unknownType11 = "
              << type_id_with_cvr<decltype(unknownType11)>().pretty_name()
              << '\n';

    std::cout << "type of unknownType14 = "
              << type_id_with_cvr<decltype(unknownType14)>().pretty_name()
              << '\n';

    std::cout << "type of unknownFunc = "
              << type_id_with_cvr<decltype(unknownFunc)>().pretty_name()
              << '\n';

    std::cout << "type of size11 = "
              << type_id_with_cvr<decltype(size11)>().pretty_name()
              << '\n';

}