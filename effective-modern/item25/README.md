## Use std::move on rvalue references, std::forward on universal references
Rvalue references bind `only to` objects that are candidates for moving. A universal reference, on the other hand, `might be` bound to an object that’s eligible for moving. 
In short, rvalue references should be unconditionally cast to rvalues (via std::move) when forwarding them to other functions, because they’re always bound to rvalues, and universal references should be conditionally cast to rvalues (via std::forward) when forwarding them, because they’re only sometimes bound to rvalues.
```
Matrix // by-value return
operator+(Matrix && lhs, const Matrix & rhs) // rvalue reference param
{
    lhs += rhs;
    return std::move(lhs); // move into return
}

template <typename T>                  // by-value return
decltype(auto) reduceAndCopy(T &&frac) // universal reference param
{
    return std::forward<T>(frac); // forward into return
}
```
In some cases, you’ll want to use the object bound to an rvalue reference or a universal reference more than once in a single function, and you’ll want to make sure that it’s not moved from until you’re otherwise done with it. In that case, you’ll want to apply std::move (for rvalue references) or std::forward (for universal references) to only the final use of the reference. 

If you’re in a function that `returns by value`, and you’re `returning an object bound to an rvalue reference or a universal reference`, you’ll want to apply std::move or std::forward when you return the reference.
However this is not applicable given a function `returning a local variable by value`. 
```
Widget makeWidget() // "Copying" version of makeWidget
{
  Widget w;         // local variable
  return w;         // "copy" w into return value
  //   return std::move(w);  // (don't do this!)
} 
```

 “Copying” version of makeWidget can avoid the need to copy the local variable w by constructing it in the memory alloted for the function’s return value. This is known as the return value optimization (`RVO`).  
 
 compilers may elide the copying (or moving) of a local object in a function that returns by value if
 1. the type of the local object is the same as that returned by the function
 2. the local object is what’s being returned.

 Both conditions are fulfilled here, and every decent C++ compiler will employ the RVO to avoid copying w. That means that the “copying” version of makeWidget doesn’t, in fact, copy anything (copy elision). 

 Developers trying to help their compilers optimize by applying std::move to a local variable that’s being returned are actually limiting the optimization options available to their compilers! RVO goes on to say that if the conditions for the RVO are met, but compilers choose not to perform copy elision, the object being returned must be treated as an `rvalue`. In effect, the Standard requires that when the RVO is permitted, either copy elision takes place or `std::move is implicitly applied to local objects being returned`. 
 If you use std::move on a local object being returned from a function that’s returning by value, you can’t help your compilers but you can certainly hinder them.  
 The situation is similar for by-value function parameters. They’re not eligible for copy elision with respect to their function’s return value, but compilers must treat them as rvalues if they’re returned.
### THINGS TO REMEMBER
* Apply std::move to rvalue references and std::forward to universal references the last time each is used.
* Do the same thing for rvalue references and universal references being returned from functions that return by value.
* Never apply std::move or std::forward to local objects if they would otherwise be eligible for the return value optimization.