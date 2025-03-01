## Consider pass by value for copyable parameters that are cheap to move and always copied

For efficiency, a function should copy lvalue arguments, but move rvalue arguments. Is there were a way to write functions such that lvalues were copied, rvalues were moved? Function overload for each type, universal reference and pass by value. 

```
pass by value approach for C++11

void addName(std::string newName)           // take lvalue or
{ names.push_back(std::move(newName)); }    // rvalue; move it
```

In C++98, no matter what callers passed in, the parameter newName would be created by copy construction. In C++11, however, newName will be copy constructed only for lvalues and it will be move constructed, for rvalues. lvalues are thus copied, and rvalues are moved, just like we want.  
Look again at this Item’s title:    
`Consider pass by value for copyable parameters that are cheap to move and always copied`   

It’s worded the way it is for a reason. Four reasons,
* only consider using pass by value - requires writing only one function
* only for copyable parameters - if they’re not copyable, copy must be created via the move constructor (passing in rvalues). But for move-only types, there is no need to provide an overload for lvalue arguments, That means that only rvalue arguments need to be supported. 
    ```
    w.setPtr(std::make_unique<std::string>("Modern C++"));
    ```
* cheap to move - the cost of an extra one may be acceptable
* always copied. - incurs the cost of constructing and destroying objects without copying

Even when you’re dealing with a function performing an unconditional copy on a copyable type that’s cheap to move, there are times when pass by value may not be appropriate :(.    
When a parameter is copied using assignment, the situation is more complicated. So, when parameters are copied via assignment, analyzing the cost of pass by value is complicated. Usually, the most practical approach is you use overloading or universal references instead of pass by value unless it’s been demonstrated that pass by value yields acceptably efficient code for the parameter type you need.
for software that must be as fast as possible, pass by value may not be a viable strategy.  
An issue unrelated to performance, but still worth keeping in mind, is that pass by value, unlike pass by reference, is susceptible to the slicing problem. There are good reasons why one of the first things you probably learned about C++ programming was to avoid passing objects of user-defined types by value. C++11 doesn’t fundamentally change the C++98 wisdom regarding pass by value. In general, pass by value still entails a performance hit you’d prefer to avoid, and pass by value can still lead to the slicing problem. What’s new in C++11 is the distinction between lvalue and rvalue arguments.
### THINGS TO REMEMBER
* For copyable, cheap-to-move parameters that are always copied, pass by value may be nearly as efficient as pass by reference, it’s easier to implement, and it can generate less object code.
* For lvalue arguments, pass by value (i.e., copy construction) followed by move assignment may be significantly more expensive than pass by reference followed by copy assignment.
* Pass by value is subject to the slicing problem, so it’s typically inappropriate for base class parameter types.