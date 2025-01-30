### Differentiate between inheritance of interface and inheritance of implementation
Two most salient features of pure virtual functions are that, they must be redeclared by any concrete class that inherits them, and they typically have no definition in abstract classes. Member function `interfaces` are always inherited regardless of access specifier. 
* The purpose of declaring a pure virtual function is to have derived classes inherit a function interface only.
* The purpose of declaring a simple virtual function is to have derived classes inherit a function interface as well as a default implementation. 
* The purpose of declaring a non-virtual function is to have derived classes inherit a function interface as well as a mandatory implementation.

The differences in declarations for pure virtual, simple virtual, and non-virtual functions allow you to specify with precision what you want derived classes to inherit: interface only, interface and a default implementation, or interface and a mandatory implementation, respectively. 
#### THINGS TO REMEMBER
* Inheritance of interface is different from inheritance of implementation. Under public inheritance, derived classes always inherit base class interfaces.

* Pure virtual functions specify inheritance of interface only.

* Simple (impure) virtual functions specify inheritance of interface plus inheritance of a default implementation.

* Non-virtual functions specify inheritance of interface plus inheritance of a mandatory implementation.
