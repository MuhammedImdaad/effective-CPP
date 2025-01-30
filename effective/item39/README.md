### Use private inheritance judiciously
Rules governing private inheritance
* Compilers will generally not convert a derived class object (such as Student) into a base class object (such as Person) if the inheritance relationship between the classes is private
* Members inherited from a private base class become private members of the derived class, even if they were protected or public in the base class

If you make a class D privately inherit from a class B, you do so because you are interested in taking advantage of some of the features available in class B, not because there is any conceptual relationship between objects of types B and D. See the example with comments. 

Prefer public inheritance plus composition over private inheritance.
#### THINGS TO REMEMBER
* Private inheritance means is-implemented-in-terms of. It's usually inferior to composition, but it makes sense when a derived class needs access to protected base class members or needs to redefine inherited virtual functions.

* Unlike composition, private inheritance can enable the empty base optimization. This can be important for library developers who strive to minimize object sizes.