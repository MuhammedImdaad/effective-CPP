## Make const member functions thread safe
Conceptually, const member functions doesn’t change the object on which it operates, but, as part of its activity, it may need to modify certain fields that do not directly change the state of the object (Ex: Caching). That’s a classic use case for `mutable`. This function has undefined behavior in multithreaded applications. The problem is the member function is declared const, but it’s not thread safe. The easiest way to address the issue is employing a `mutex`.   
In some situations, a mutex is overkill where std::`atomic` can serve the purpose. For a single variable or memory location requiring synchronization, use of a std::atomic is adequate, but once you get to two or more variables or memory locations that require manipulation as a unit, you should reach for a mutex.     
`const member functions will be subject to concurrent execution, and that’s why you should ensure that your const member functions are thread safe.`

### THINGS TO REMEMBER
* Make const member functions thread safe unless you’re certain they’ll never be used in a concurrent context.
* Use of std::atomic variables may offer better performance than a mutex, but they’re suited for manipulation of only a single variable or memory location.