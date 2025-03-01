#include <iostream>
#include <boost/type_index.hpp>

template <typename T> // declaration only for TD;
class TD;             // TD == "Type Displayer"

template <typename T> 
void f(const T &param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;

    // show T
    cout << "T =\t"
         << type_id_with_cvr<T>().pretty_name()
         << '\n';

    // show param's type
    cout << "param =\t"
         << type_id_with_cvr<decltype(param)>().pretty_name()
         << '\n';
}