# effective-CPP

This is a curated list of learning content that I found best to be kept after going through scott mayers effective C++ books.
* https://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876 

    Accustoming Yourself to C++
    * Item 1: View C++ as a federation of languages
    * Item 2: Prefer consts, enums, and inlines to #defines
    * Item 3: Use const whenever possible
    * Item 4: Make sure that objects are initialized before they're used
    Constructors, Destructors, and Assignment Operators
    * Item 5: Know what functions C++ silently writes and calls
    * Item 6: Explicitly disallow the use of compiler-generated functions you do not want
    * Item 7: Declare destructors virtual in polymorphic base classes
    * Item 8: Prevent exceptions from leaving destructors
    * Item 9: Never call virtual functions during construction or destruction
    * Item 10: Have assignment operators return a reference to *this
    * Item 11: Handle assignment to self in operator=
    * Item 12: Copy all parts of an object
    Resource Management
    * Item 13: Use objects to manage resources
    * Item 14: Think carefully about copying behavior in resource-managing classes
    * Item 15: Provide access to raw resources in resource-managing classes
    * Item 16: Use the same form in corresponding uses of new and delete
    * Item 17: Store newed objects in smart pointers in standalone statements
    Designs and Declarations
    * Item 18: Make interfaces easy to use correctly and hard to use incorrectly
    * Item 19: Treat class design as type design
    * Item 20: Prefer pass-by-reference-to-const to pass-by-value
    * Item 21: Don't try to return a reference when you must return an object
    * Item 22: Declare data members private
    * Item 23: Prefer non-member non-friend functions to member functions
    * Item 24: Declare non-member functions when type conversions should apply to all parameters
    * Item 25: Consider support for a non-throwing swap
    Implementations
    * Item 26: Postpone variable definitions as long as possible
    * Item 27: Minimize casting
    * Item 28: Avoid returning “handles” to object internals
    * Item 29: Strive for exception-safe code
    * Item 30: Understand the ins and outs of inlining
    * Item 31: Minimize compilation dependencies between files
    Inheritance and Object-Oriented Design
    * Item 32: Make sure public inheritance models “is-a.”
    * Item 33: Avoid hiding inherited names
    * Item 34: Differentiate between inheritance of interface and inheritance of implementation
    * Item 35: Consider alternatives to virtual functions
    * Item 36: Never redefine an inherited non-virtual function
    * Item 37: Never redefine a function's inherited default parameter value
    * Item 38: Model “has-a” or “is-implemented-in-terms-of” through composition
    * Item 39: Use private inheritance judiciously
    * Item 40: Use multiple inheritance judiciously