### Familiarize yourself with the standard library, including TR1
It's worth reviewing the major parts of the standard C++ library specified by C++98.
* The Standard Template Library (STL)
* Iostreams
* Support for internationalization
* Support for numeric processing
* An exception hierarchy
* C89's standard library

TR1 specifies 14 new components and all new utilities were later incorporated into C++11 and beyond. The overall guideline is that developers should leverage the C++ Standard Library to avoid reinventing the wheel and benefit from well-tested, efficient implementations.
### Things to Remember
* The primary standard C++ library functionality consists of the STL, iostreams, and locales. The C99 standard library is also included.

* TR1 adds support for smart pointers (e.g., tr1::shared_ptr), generalized function pointers (tr1::function), hash-based containers, regular expressions, and 10 other components.

* TR1 itself is only a specification. To take advantage of TR1, you need an implementation. One source for implementations of TR1 components is Boost. Subsequently, all new utilities were later incorporated into C++11 and beyond.

