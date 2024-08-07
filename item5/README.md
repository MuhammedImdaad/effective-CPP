 ###  Constructors, Destructors, and Assignment Operators

 If you don't declare them yourself, compilers will declare their own versions of a copy constructor, a copy assignment operator, and a destructor and if you declare no constructors at all, compilers will also declare a default constructor for you.
 As for the copy constructor and the copy assignment operator, the compiler-generated versions simply copy each non-static data member of the source object over to the target object.
 once a custome constructor is declared in NamedObject, compilers won't generate a default constructor.
 If you want to support assignment in a class containing a reference member, classes containing const members, in derived classes that inherit from base classes declaring the copy assignment operator private; you must define the copy assignment operator yourself. Compilers rejects otherwise stating copy assignment is implicitly deleted because the default definition would be ill-formed. Reference members must be initialized upon creation and cannot be changed to refer to another object. To properly handle the reference member, we can make the class non-copyable and non-assignable.

#### THINGS TO REMEMBER
* Compilers may implicitly generate a class's default constructor, copy constructor, copy assignment operator, and destructor.