### Consider support for a non-throwing swap

Along with `swap` singular importance comes a set of singular complications. For spcific types (pimpl idiom), the default swap puts you on the fast track to the slow lane.

1. If the default implementation of swap offers acceptable efficiency for your class or class template, you don't need to do anything.
2. If the default implementation of swap isn't efficient enough (pimpl idiom), do the following:
    
*  Offer a public swap member function that efficiently swaps the value of two objects of your type.
* Offer a non-member swap in the same namespace as your class or template. Have it call your swap member function.
* If you're writing a class (not a class template), specialize std::swap for your class. Have it also call your swap member function.
3. Finally, if you're calling swap, be sure to include a `using` declaration to make std::swap visible in your function, then call swap without any namespace qualification.

#### THINGS TO REMEMBER
* Provide a swap member function when std::swap would be inefficient for your type. Make sure your swap doesn't throw exceptions.
* If you offer a member swap, also offer a non-member swap that calls the member. For classes (not templates), specialize std::swap, too.
* When calling swap, employ a using declaration for std::swap, then call swap without namespace qualification.
* It's fine to totally specialize std templates for user-defined types, but never try to add something completely new to std.