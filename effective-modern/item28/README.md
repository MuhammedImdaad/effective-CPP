## Understand reference collapsing
In a universal reference template, the deduced template parameter T will encode whether the argument passed to param was an lvalue or an rvalue. When an lvalue is passed as an argument, T is deduced to be an lvalue reference (Widget&). When an rvalue is passed, T is deduced to be a non-reference (Widget).  
Generally you are forbidden from declaring references to reference as it is illegal in C++. But compilers may produce them in particular contexts, template instantiation being among them. When compilers generate references to references, `reference collapsing` dictates what happens next. If either reference is an lvalue reference, the result is an lvalue reference. Otherwise (i.e., if both are rvalue references) the result is an rvalue reference.  
```
void func(T && param); // for lvalue
T - Widget& 
void func(Widget& && param);
void func(Widget& param);

void func(T && param); // for rvalue
T - Widget 
void func(Widget && param);
void func(Widget&& param);
```
Reference collapsing is a key part of what makes std::forward work. 
Reference collapsing occurs in four contexts.
1. template instantiation.
2. type generation for auto variables.
3. generation and use of typedefs and alias declarations. 
4. uses of decltype.
### THINGS TO REMEMBER
* Reference collapsing occurs in four contexts: template instantiation, auto type generation, creation and use of typedefs and alias declarations, and decltype.
* When compilers generate a reference to a reference in a reference collapsing context, the result becomes a single reference. If either of the original references is an lvalue reference, the result is an lvalue reference. Otherwise it’s an rvalue reference.
* Universal references are rvalue references in contexts where type deduction distinguishes lvalues from rvalues and where reference collapsing occurs.