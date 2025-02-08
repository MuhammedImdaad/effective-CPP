## Prefer const_iterators to iterators
const_iterators are the STL equivalent of pointers-to-const. They point to values that may not be modified. In C++98, the process of getting const_iterators to elements of a non-const container involved some amount of contorting. C++98, const_iterators just weren’t very practical. All that changed in C++11. Now const_iterators are both easy to get and easy to use. The point of this Item is to encourage you to use const_iterators whenever you can. For modern C++ code, range-based for loops often replace explicit iterator declarations. Use cbegin and cend (C++11) instead of begin and end for clarity. 

When Not to Prefer const_iterators?
If you need to modify elements during iteration.
### THINGS TO REMEMBER
* Prefer const_iterators to iterators.
* In maximally generic code, prefer non-member versions of begin, end, rbegin, etc., over their member function counterparts.
