 ### Use const whenever possible 

If the word const appears to the left of the asterisk, what's pointed to is constant; 
if the word const appears to the right of the asterisk, the pointer itself is constant;
If you want an iterator that points to something that can't be modified (i.e., the STL analogue of a const T* pointer), you want a const_iterator
const member functions are important for two reasons. First, they make the interface of a class easier to understand. It's important to know which functions may modify an object and which may not. Second, they make it possible to work with const objects.
keyword mutable frees non-static data members from the constraints of bitwise constness. You can modify a mutable member through a const method.

#### THINGS TO REMEMBER
* Declaring something const helps compilers detect usage errors. const can be applied to objects at any scope, to function parameters and return types, and to member functions as a whole.

* Compilers enforce bitwise constness, but you should program using conceptual constness.

* When const and non-const member functions have essentially identical implementations, code duplication can be avoided by having the non-const version call the const version.