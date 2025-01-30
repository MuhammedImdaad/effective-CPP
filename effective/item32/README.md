### Make sure public inheritance models “is-a.”
The single most important rule in object-oriented programming with C++ is this: public inheritance means “is-a.” Commit this rule to memory. If you write that class D (“Derived”) publicly inherits from class B (“Base”), every object of type D is an object of type B. But not vice versa.
#### THINGS TO REMEMBER
* Public inheritance means “is-a.” Everything that applies to base classes must also apply to derived classes, because every derived class object is a base class object.
