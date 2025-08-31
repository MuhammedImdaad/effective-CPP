## Declare functions noexcept if they won’t emit exceptions
Most programmers ultimately decided that C++98 exception specifications weren’t worth the trouble. During work on C++11, a consensus emerged that the truly meaningful information about a function’s exception-emitting behavior was whether it had any. Black or white, either a function might emit an exception or it guaranteed that it wouldn’t. In C++11, unconditional noexcept is for functions that guarantee they won’t emit exceptions.     
The exception-emitting behavior of a function is of key interest to clients. Failure to declare a function noexcept when you know that it won’t emit an exception is simply poor interface specification. It permits compilers to generate better object code.  
However, Optimization is important, but correctness is more important. most functions are exception-neutral. Such functions throw no exceptions themselves, but functions they call might emit one. Exception-neutral functions are never noexcept. `When you can honestly say that a function should never emit exceptions, you should definitely declare it noexcept.`  
By default, all memory deallocation functions and all destructors—both user-defined and compiler-generated—are implicitly noexcept. 
### THINGS TO REMEMBER
* noexcept is part of a function’s interface, and that means that callers may depend on it.
* noexcept functions are more optimizable than non-noexcept functions.
* noexcept is particularly valuable for the move operations, swap, memory deallocation functions, and destructors.
* most functions are exception-neutral rather than noexcept.