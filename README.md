# effective-CPP

This is a curated list of learning content that I found best to be kept after going through scott mayers effective C++ books.
* https://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876 

    * Item 1: View C++ as a federation of languages
    * Item 2: Prefer consts, enums, and inlines to #defines
    * Item 3: Use const whenever possible
    * Item 4: Make sure that objects are initialized before they're used
    * Item 5: Know what functions C++ silently writes and calls
    * Item 6: Explicitly disallow the use of compiler-generated functions you do not want
    * Item 7: Declare destructors virtual in polymorphic base classes
    * Item 8: Prevent exceptions from leaving destructors
    * Item 9: Never call virtual functions during construction or destruction
    * Item 10: Have assignment operators return a reference to *this
    * Item 11: Handle assignment to self in operator=
    * Item 12: Copy all parts of an object
    * Item 13: Use objects to manage resources
    * Item 14: Think carefully about copying behavior in resource-managing classes
    * Item 15: Provide access to raw resources in resource-managing classes
    * Item 16: Use the same form in corresponding uses of new and delete
    * Item 17: Store newed objects in smart pointers in standalone statements
    * Item 18: Make interfaces easy to use correctly and hard to use incorrectly
    * Item 19: Treat class design as type design
