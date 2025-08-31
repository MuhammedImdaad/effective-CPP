## Understand std::move and std::forward
A useful heuristic to determine whether an expression is an lvalue is to ask if you can take its address. If you can, it typically is. If you can’t, it’s usually an rvalue. 
When we talk about rvalue or lvalue references we are talking about how the expression is passed onto the function which binds to the parameter, not directly about object construction. 

It’s especially important to remember this when dealing with a parameter of rvalue reference type, because `the parameter itself is an lvalue`.  
```
Widget(Widget&& rhs);    // rhs is an lvalue, though it has an rvalue reference type
```
It’d be perfectly valid to take rhs’s address inside Widget’s move constructor, so rhs is an lvalue, even though its type is an rvalue reference.

It’s useful to approach std::move and std::forward in terms of what they don’t do. `std::move doesn’t move anything. std::forward doesn’t forward anything.` At runtime, neither does anything at all. They generate no executable code.  
It’s important to remember what std::move does and doesn’t do. It does cast. It doesn’t move.  
Moving a value out of an object generally modifies the object, so the language should not permit const objects to be passed to functions (such as move constructors) that could modify them.
```
Widget(Widget&& rhs)
```
Don’t declare objects const if you want to be able to move from them. `Move requests on const objects are silently transformed into copy operations (example).` The only thing you know for sure about the result of applying std::move to an object is that it’s an rvalue.

`std::forward is a conditional cast. It casts to an rvalue only if its argument was initialized with an rvalue.`  
More importantly, the use of `std::move conveys an unconditional cast to an rvalue`, while the use of std::forward indicates a cast to an rvalue only for references to which rvalues have been bound. Those are two very different actions. The first one typically sets up a move, while the second one just passes—forwards—an object to another function in a way that retains its original lvalueness or rvalueness. 
### THINGS TO REMEMBER
* std::move performs an unconditional cast to an rvalue. In and of itself, it doesn’t move anything.
* std::forward casts its argument to an rvalue only if that argument is bound to an rvalue.
* Neither std::move nor std::forward do anything at runtime.