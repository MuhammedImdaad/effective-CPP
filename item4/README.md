## Know how to view deduced types
viewing the results of type deduction is dependent on the phase of the software development process where you want the information. three possibilities: 
* getting type deduction information as you edit your code
* getting it during compilation
* getting it at runtime

what makes it possible for the IDE to offer this kind of information is a C++ compiler (or at least the front end of one) running inside the IDE.   
A generally effective way to get a compiler to show a type it has deduced is to use that type in a way that leads to compilation problems.  
Runtime Output, sadly, the results of std::type_info::name( typeid(x).name() ) are not reliable. Boost TypeIndex library (often written as Boost.TypeIndex) is designed for this purpose.   

All can be helpful, but at the end of the day, there’s no substitute for understanding the type deduction information in Items 1–3.

### THINGS TO REMEMBER
* Deduced types can often be seen using IDE editors, compiler error messages, and the Boost TypeIndex library.
* The results of some tools may be neither helpful nor accurate, so an understanding of C++’s type deduction rules remains essential.

