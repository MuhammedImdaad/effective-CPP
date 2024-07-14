### Make interfaces easy to use correctly and hard to use incorrectly
Ideally, if an attempted use of an interface won't do what the client expects, the code should't compile; and if the code does compile, it should do what the client wants.
Many client errors can be prevented for function arguments by the introduction of new types. Once the right types are in place, it can sometimes be reasonable to restrict the values of those types. Unless there's a good reason not to, have your types behave consistently with the built-in types like having `const` wherever possible. Smart pointers and enum (C++11 enum classes a better way to deal with client problems)

#### THINGS TO REMEMBER
* Good interfaces are easy to use correctly and hard to use incorrectly. Your should strive for these characteristics in all your interfaces.

* Ways to facilitate correct use include consistency in interfaces and behavioral compatibility with built-in types.

* Ways to prevent errors include creating new types, restricting operations on types, constraining object values, and eliminating client resource management responsibilities.

* tr1::shared_ptr supports custom deleters. This prevents the cross-DLL problem, can be used to automatically unlock mutexes, etc.