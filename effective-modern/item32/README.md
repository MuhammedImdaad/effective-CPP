## Use init capture to move objects into closures
If you have a move-only object (e.g., a std::unique_ptr or a std::future) that you want to get into a closure, C++14 offers direct support for moving objects into closures. The new capability is called `init capture`. It can do virtually everything the C++11 capture forms can do, plus more.
```
auto func = [pw = std::move(pw)](args){body}; 
```
“pw = std::move(pw)” means “create a data member pw in the closure, and initialize that data member with the result of applying std::move to the local variable pw.” C++14 notion of “capture” is considerably generalized from C++11, because in C++11, it’s not possible to capture the result of an expression. As a result, another name for init capture is `generalized lambda capture`.  
lambda expression is simply a way to cause a class to be generated and an object of that type to be created.
### THINGS TO REMEMBER
* Use C++14’s init capture to move objects into closures.
* In C++11, emulate init capture via hand-written classes or std::bind.