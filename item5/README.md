## Prefer auto to explicit type declarations
The advantages of auto extend beyond the three main advantages of avoidance of uninitialized variables, verbose variable declarations, and the ability to directly hold closures.

std::function is a template in the C++11 Standard Library that generalizes the idea of a function pointer. the std::function approach is generally bigger (mem footprint) and slower (runtime) than the auto approach. 

Some developers are disturbed by the fact that using auto eliminates the ability to determine an object’s type by a quick glance at the source code. However, IDEs’ ability to show object types often mitigates this problem. The fact of the matter is that writing types explicitly often does little more than introduce opportunities for subtle errors, either in correctness or efficiency or both.
### THINGS TO REMEMBER
* auto variables must be initialized, are generally immune to type mismatches that can lead to portability or efficiency problems, can ease the process of refactoring, and typically require less typing than variables with explicitly specified types.

* auto-typed variables are subject to the pitfalls described in Items 2 and 6. 