## Understand special member function generation
C++98 has four special member functions: 
1. default constructor
2. destructor
3. copy constructor 
4. copy assignment operator  

default constructor is generated only if the class declares no constructors at all. Generated special member functions are implicitly public and inline, and they’re nonvirtual unless the function in question is a destructor in a derived class inheriting from a base class with a virtual destructor.  
As of C++11, the special member functions club has two more inductees: the `move constructor`and the `move assignment` operator. The move operations are generated only if they’re needed, and if they are generated, they perform “memberwise moves” on the `non-static data members` of the class. The heart of each memberwise “move” is the application of `std::move` to the object to be moved from, and the result is used during function overload resolution to determine whether a move or a copy should be performed. simply remember that a memberwise move consists of move operations on data members and base classes that support move operations, but a copy operation for those that don’t.     

The two copy operations are independent: declaring one doesn’t prevent compilers from generating the other. The two move operations are not independent. If you declare either, that prevents compilers from generating the other. Furthermore, move operations won’t be generated for any class that explicitly declares a copy operation. The Rule of Three states that if you declare any of a copy constructor, copy assignment operator, or destructor, you should declare all three.  
move operations are generated for classes (when needed) only if these three things are true:

* No copy operations are declared in the class.
* No move operations are declared in the class.
* No destructor is declared in the class.

At some point, analogous rules may be extended to the copy operations, because C++11 deprecates the automatic generation of copy operations for classes declaring copy operations or a destructor. If the behavior of the compiler-generated functions is correct, C++11’s `= default` lets you say that explicitly.    
the class declares no copy operations, no move operations, and no destructor, compilers will automatically generate these functions if they are used. The C++11 rules governing the special member functions are thus:
* Default constructor: Same rules as C++98. Generated only if the class contains no user-declared constructors.
* Destructor: Essentially same rules as C++98; sole difference is that destructors are noexcept by default. As in C++98, virtual only if a base class destructor is virtual.
* Copy constructor/Copy assignment operator:: Same runtime behavior as C++98: memberwise copy construction/assignment of non-static data members. Generated only if the class lacks a user-declared copy constructor. Deleted if the class declares a move operation. Generation of this function in a class with a user-declared copy assignment operator or destructor is deprecated.
* Move constructor and move assignment operator: Each performs memberwise moving of non-static data members. Generated only if the class contains no user-declared copy operations, move operations, or destructor.
* There’s nothing in the rules about the existence of a member function template preventing compilers from generating the special member functions. 

### THINGS TO REMEMBER
* The special member functions are those compilers may generate on their own: default constructor, destructor, copy operations, and move operations.
* Move operations are generated only for classes lacking explicitly declared move operations, copy operations, or a destructor.
* The copy constructor is generated only for classes lacking an explicitly declared copy constructor, and it’s deleted if a move operation is declared. The copy assignment operator is generated only for classes lacking an explicitly declared copy assignment operator, and it’s deleted if a move operation is declared. Generation of the copy operations in classes with an explicitly declared destructor is deprecated.
* Member function templates never suppress generation of special member functions.