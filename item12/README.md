## Declare overriding functions override
For overriding to occur, several requirements must be met:
* The base class function must be virtual.
* The base and derived function names must be identical (except in the case of destructors).
* The parameter types of the base and derived functions must be identical.
* The constness of the base and derived functions must be identical.
* The return types and exception specifications of the base and derived functions must be compatible.
* The functions’ reference qualifiers must be identical. (C++11)

All these requirements for overriding mean that small mistakes can make a big difference. Declaring derived class overrides is important to get right, but easy to get wrong, C++11 gives you a way to make explicit that a derived class function is supposed to override a base class version: declare it override.
### THINGS TO REMEMBER
* Declare overriding functions override.
* Member function reference qualifiers make it possible to treat lvalue and rvalue objects (*this) differently.