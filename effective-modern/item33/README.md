## Use decltype on auto&& parameters to std::forward them
One of the most exciting features of C++14 is `generic lambdas`—lambdas that use `auto` in their parameter specifications. Closure class's `Operator()` becomes templatized. 
``` 
auto f = [](auto x)
{ 
    return normalize(x); 
}; 
```
The correct way to write the lambda is to have it `perfect-forward` x to normalize.     
If an lvalue was passed in, decltype(x) will produce a type that’s an lvalue reference. If an rvalue was passed, decltype(x) will produce an rvalue reference type. Applying the `reference-collapsing rule` that an rvalue reference to an rvalue reference becomes a single rvalue reference (&& && -> &&). That's the same outcome as the conventional universal reference forwarding.   
Our perfect-forwarding lambda can therefore be written like this:
```
auto f = [](auto&& x)
{ 
    return std::forward<decltype(x)>(x); 
};
```
### THINGS TO REMEMBER
* Use decltype on auto&& parameters to std::forward them.