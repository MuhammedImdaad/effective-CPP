### Minimize casting
C++ offers four new cast forms
* const_cast<T>(expression) - cast away the constness
* reinterpret_cast<T>(expression) - should be rare outside low-level code
* static_cast<T>(expression) - force implicit conversions
* dynamic_cast<T>(expression) - perform “safe downcasting. The need for dynamic_cast generally arises because you want to perform derived class operations on what you *believe to be a* derived class object

#### THINGS TO REMEMBER
* Avoid casts whenever practical, especially dynamic_casts in performance-sensitive code. If a design requires casting, try to develop a cast-free alternative.

* When casting is necessary, try to hide it inside a function. Clients can then call the function instead of putting casts in their own code.
* Prefer C++-style casts to old-style casts. They are easier to see, and they are more specific about what they do.
