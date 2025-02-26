# Effective C++

This is a curated list of learning content that I found best to be kept after going through scott mayers effective C++ books.
* [Effective C++, Third Edition](https://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876) 

    1. Accustoming Yourself to C++
    * Item 1: View C++ as a federation of languages
    * Item 2: Prefer consts, enums, and inlines to #defines
    * Item 3: Use const whenever possible
    * Item 4: Make sure that objects are initialized before they're used
    2. Constructors, Destructors, and Assignment Operators
    * Item 5: Know what functions C++ silently writes and calls
    * Item 6: Explicitly disallow the use of compiler-generated functions you do not want
    * Item 7: Declare destructors virtual in polymorphic base classes
    * Item 8: Prevent exceptions from leaving destructors
    * Item 9: Never call virtual functions during construction or destruction
    * Item 10: Have assignment operators return a reference to *this
    * Item 11: Handle assignment to self in operator=
    * Item 12: Copy all parts of an object
    3. Resource Management
    * Item 13: Use objects to manage resources
    * Item 14: Think carefully about copying behavior in resource-managing classes
    * Item 15: Provide access to raw resources in resource-managing classes
    * Item 16: Use the same form in corresponding uses of new and delete
    * Item 17: Store newed objects in smart pointers in standalone statements
    4. Designs and Declarations
    * Item 18: Make interfaces easy to use correctly and hard to use incorrectly
    * Item 19: Treat class design as type design
    * Item 20: Prefer pass-by-reference-to-const to pass-by-value
    * Item 21: Don't try to return a reference when you must return an object
    * Item 22: Declare data members private
    * Item 23: Prefer non-member non-friend functions to member functions
    * Item 24: Declare non-member functions when type conversions should apply to all parameters
    * Item 25: Consider support for a non-throwing swap
    5. Implementations
    * Item 26: Postpone variable definitions as long as possible
    * Item 27: Minimize casting
    * Item 28: Avoid returning “handles” to object internals
    * Item 29: Strive for exception-safe code
    * Item 30: Understand the ins and outs of inlining
    * Item 31: Minimize compilation dependencies between files
    6. Inheritance and Object-Oriented Design
    * Item 32: Make sure public inheritance models “is-a.”
    * Item 33: Avoid hiding inherited names
    * Item 34: Differentiate between inheritance of interface and inheritance of implementation
    * Item 35: Consider alternatives to virtual functions
    * Item 36: Never redefine an inherited non-virtual function
    * Item 37: Never redefine a function's inherited default parameter value
    * Item 38: Model “has-a” or “is-implemented-in-terms-of” through composition
    * Item 39: Use private inheritance judiciously
    * Item 40: Use multiple inheritance judiciously
    7. Templates and Generic Programming
    * Item 41: Understand implicit interfaces and compile-time polymorphism
    * Item 42: Understand the two meanings of typename
    * Item 43: Know how to access names in templatized base classes
    * Item 44: Factor parameter-independent code out of templates
    * Item 45: Use member function templates to accept “all compatible types.”
    * Item 46: Define non-member functions inside templates when type conversions are desired
    * Item 47: Use traits classes for information about types
    * Item 48: Be aware of template metaprogramming
    8. Customizing new and delete
    * Item 49: Understand the behavior of the new-handler
    * Item 50: Understand when it makes sense to replace new and delete
    * Item 51: Adhere to convention when writing new and delete
    * Item 52: Write placement delete if you write placement new
    9. Miscellany
    * Item 53: Pay attention to compiler warnings
    * Item 54: Familiarize yourself with the standard library, including TR1
    * Item 55: Familiarize yourself with Boost

* [Effective Modern C++](https://www.amazon.com/Effective-Modern-Specific-Ways-Improve-ebook/dp/B00PGCMGDQ)
    
    1. Deducing Types
    * Item 1: Understand template type deduction
    * Item 2: Understand auto type deduction
    * Item 3: Understand decltype
    * Item 4: Know how to view deduced types
    2. auto
    * Item 5: Prefer auto to explicit type declarations
    * Item 6: Use the explicitly typed initializer idiom when auto deduces undesired types
    3. Moving to Modern C++
    * Item 7: Distinguish between () and {} when creating objects
    * Item 8: Prefer nullptr to 0 and NULL
    * Item 9: Prefer alias declarations to typedefs
    * Item 10: Prefer scoped enums to unscoped enums
    * Item 11: Prefer deleted functions to private undefined ones
    * Item 12: Declare overriding functions override
    * Item 13: Prefer const_iterators to iterators
    * Item 14: Declare functions noexcept if they won’t emit exceptions
    * Item 15: Use constexpr whenever possible
    * Item 16: Make const member functions thread safe
    * Item 17: Understand special member function generation
    4. Smart Pointers
    * Item 18: Use std::unique_ptr for exclusive-ownership resource management
    * Item 19: Use std::shared_ptr for shared-ownership resource management
    * Item 20: Use std::weak_ptr for std::shared_ptr-like pointers that can dangle
    * Item 21: Prefer std::make_unique and std::make_shared to direct use of new
    * Item 22: When using the Pimpl Idiom, define special member functions in the implementation file
    5. Rvalue References, Move Semantics, and Perfect Forwarding
    * Item 23: Understand std::move and std::forward
    * Item 24: Distinguish universal references from rvalue references
    * Item 25: Use std::move on rvalue references, std::forward on universal references
    * Item 26: Avoid overloading on universal references
    * Item 27: Familiarize yourself with alternatives to overloading on universal references
    * Item 28: Understand reference collapsing
    * Item 29: Assume that move operations are not present, not cheap, and not used
    * Item 30: Familiarize yourself with perfect forwarding failure cases
    6. Lambda Expressions
    * Item 31: Avoid default capture modes
    * Item 32: Use init capture to move objects into closures
    * Item 33: Use decltype on auto&& parameters to std::forward them
    * Item 34: Prefer lambdas to std::bind