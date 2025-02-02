## Understand auto type deduction
educing types for auto is, with only one exception, the same as deducing types for templates.

exception :    
auto x3 = {27}; //std::initializer_list<int>

The only real difference between auto and template type deduction is that auto assumes that a braced initializer represents a std::initializer_list, but template type deduction doesn’t. part 3. 

C++14 permits auto to indicate that a function’s return type should be deduced, and C++14 lambdas may use auto in parameter declarations. However, these uses of auto employ `template type deduction,` not auto type deduction. part 4.
### THINGS TO REMEMBER
* auto type deduction is usually the same as template type deduction, but auto type deduction assumes that a braced initializer represents a std::initializer_list, and template type deduction doesn’t.

* auto in a function return type or a lambda parameter implies template type deduction, not auto type deduction.