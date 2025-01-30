### Strive for exception-safe code
When an exception is thrown, exception-safe functions:

* Leak no resources
* Don't allow data structures to become corrupted

Exception-safe functions offer one of three guarantees:
* Offering the basic guarantee
    * if an exception is thrown, everything in the program remains in a valid state. However, the exact state of the program may not be predictable.
* Offering the strong guarantee
    * atomic in the sense that if they succeed, they succeed completely, and if they fail, the program state is as if they'd never been called.
    * There is a general design strategy that typically leads to the strong guarantee, and it's important to be familiar with it. The strategy is known as “copy and swap.”
* Offering the nothrow guarantee
    * promise to never to throw exceptions

There's no such thing as a partially exception-safe system. If a system has even a single function that's not exception-safe, the system as a whole is not exception-safe.
#### THINGS TO REMEMBER
* Exception-safe functions leak no resources and allow no data structures to become corrupted, even when exceptions are thrown. Such functions offer the basic, strong, or nothrow guarantees.

* The strong guarantee can often be implemented via copy-and-swap, but the strong guarantee is not practical for all functions.

* A function can usually offer a guarantee no stronger than the weakest guarantee of the functions it calls.
