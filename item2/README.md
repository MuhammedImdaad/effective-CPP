 ### Prefer consts, enums, and inlines to #defines 

 Usually, C++ requires that you provide a definition for anything you use, but class-specific constants that are static and of integral type (e.g., integers, chars, bools) are an exception. As long as you don't take their address, you can declare them and use them without providing a definition. If you do take the address of a class constant, or if your compiler incorrectly insists on a definition even if you don't take the address, you provide a separate definition.
 You put this in an implementation file, not a header file. Because the initial value of class constants is provided where the constant is declared (e.g., NumTurns is initialized to 5 when it is declared), no initial value is permitted at the point of definition.

#### THINGS TO REMEMBER
* For simple constants, prefer const objects or enums to #defines.

* For function-like macros, prefer inline functions to #defines.