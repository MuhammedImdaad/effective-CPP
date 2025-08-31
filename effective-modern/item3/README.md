## Understand decltype
Given a name or an expression, decltype tells you the name’s or the expression’s type. In contrast to what happens during type deduction for templates and auto (see [item 1](../item1/) and [item 2](../item2/)), decltype typically parrots back the exact type of the name or expression you give it.

In C++11, perhaps the primary use for decltype is declaring function templates where the function’s return type depends on its parameter types. Ex: operator[] on a container of objects of type T typically returns a T&. This is almost always is the case. For std::vector\<bool>, however, operator[] does not return a bool& but bool.  
C++11 permits return types for single-statement lambdas to be deduced (auto), and C++14 extends this to both all lambdas and all functions. C++14 further introduced the `decltype(auto) specifier. `auto` specifies that the type is to be deduced, and `decltype` says that decltype rules should be used during the deduction`. The use of `decltype(auto)` is not limited to function return types. It can also be convenient for declaring variables when you want to apply the decltype type deduction rules to the initializing expression. 

decltype almost always produces the type you expect, that it rarely surprises. However, putting parentheses around a name can change the type that decltype reports for it!
```
int x = 0;
decltype(x) is int
decltype((x)) is int&
```
### THINGS TO REMEMBER
* Decltype almost always yields the type of a variable or expression without any modifications.
* For lvalue expressions of type T other than names, decltype always reports a type of T&.

* C++14 supports decltype(auto), which, like auto, deduces a type from its initializer, but it performs the type deduction using the decltype rules. not by auto rules or template rules. 