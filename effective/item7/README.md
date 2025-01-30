 ### Declare destructors virtual in polymorphic base classes

when a derived class object is deleted through a pointer to a base class with a non-virtual destructor, results are undefined. 

#### THINGS TO REMEMBER
* Polymorphic base classes should declare virtual destructors. If a class has any virtual functions, it should have a virtual destructor.
* Classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors.