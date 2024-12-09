### Understand implicit interfaces and compile-time polymorphism
The world of templates and generic programming, implicit interfaces and compile-time polymorphism move to the fore.
```
template<typename T>
void doProcessing(T& w){}
```
 Set of expressions that must be valid in order for the template to compile is the implicit interface that `T` must support. if `typename is defined to be a concrete object` we can look up this interface in the source code (e.g., the .h file for Widget) to see exactly what it looks like, so this is called an explicit interface — one explicitly visible in the source code. Just as you can't use an object in a way contradictory to the explicit interface its class offers (the code won't compile), you can't try to use an object in a template unless that object supports the implicit interface the template requires (again, the code won't compile).
### Things to Remember
* Both classes and templates support interfaces and polymorphism.
* For classes, interfaces are explicit and centered on function signatures. Polymorphism occurs at runtime through virtual functions.
* For template parameters, interfaces are implicit and based on valid expressions. Polymorphism occurs during compilation through template instantiation and function overloading resolution.