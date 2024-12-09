#include <iostream>

template<typename C>                            // print 2nd element in
void print2nd(const C& container)               // container;
{                                               // this is not valid C++!
  if (container.size() >= 2) {
    //nested dependent type name
    typename C::const_iterator iter(container.begin()); // get iterator to 1st element
    //error: dependent-name ‘C::const_iterator’ is parsed as a non-type, but instantiation yields a type
    ++iter;                                    // move iter to 2nd element
    typename C::value_type value = *iter;                         // copy that element to an int
    std::cout << value << std::endl;                        // print the int
  }
}

template<typename ITR>
void copying(const ITR iter)
{
  typedef typename std::iterator_traits<ITR>::value_type value_type; //the type of thing pointed to by objects of type ITR
  value_type temp(*iter); //If ITR is vector<int>::iterator, temp is of type int.
  std::cout << temp << std::endl;
}