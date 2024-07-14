 ### Make sure that objects are initialized before they're used

For most types, a single call to a copy constructor is more efficient — sometimes much more efficient — than a call to the default constructor followed by a call to the copy assignment operator. Therefore make use of initilization list.
Constant (const) and reference (&) members must be initialized using an initialization list. They cannot be assigned values inside the constructor body because they must be initialized at the time of their creation. A small design cange eliminates the problem of non-local static member intitialization order. All that has to be done is to move each non-local static object into its own function, where it's declared static. 

#### THINGS TO REMEMBER
* Manually initialize objects of built-in type, because C++ only sometimes initializes them itself.

* In a constructor, prefer use of the member initialization list to assignment inside the body of the constructor. List data members in the initialization list in the same order they're declared in the class.
* Avoid initialization order problems across translation units by replacing non-local static objects with local static objects.