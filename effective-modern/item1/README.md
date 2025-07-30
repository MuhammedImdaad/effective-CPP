## Understand template type deduction
type deduction for templates is the basis for one of modern C++’s most compelling features: auto. For that reason, it’s important to truly understand the aspects of template type deduction that auto builds on. 
```
template<typename T>
void f(ParamType param);

f(expr);  
```
There are three cases:
* Case 1 : ParamType is a pointer or reference type, but not a universal reference. (Universal references are described in Item 24.)
```
If expr’s type is a reference, ignore the reference part.

template<typename T>
void f(T& param);

int x = 27;             // x is an int
const int cx = x;       // cx is a const int
const int& rx = x;      // rx is a reference to x as a const int
const char name[] = "J. P. Briggs";  // name's type is const char[13]

f(x);                   // T is int, param's type is int&
f(cx);                  // T is const int, param's type is const int&
f(rx);                  // T is const int, param's type is const int&
f(name);                // T is deduced to be const char [13], and the param's type is const char (&)[13]
```
* Case 2: ParamType is a Universal Reference
```
If expr is an lvalue, both T and ParamType are deduced to be lvalue references. If expr is an rvalue, the “normal” (i.e., Case 1) rules apply.
A useful heuristic to determine whether an expression is an lvalue is to ask if you can take its address. If you can, it typically is. If you can’t, it’s usually an rvalue. 

template<typename T>
void f(T&& param);       // param is now a universal reference

int x = 27;              // as before
const int cx = x;        // as before
const int& rx = x;       // as before

f(x);                    // x is lvalue, so T is int&, param's type is also int&
f(cx);                   // cx is lvalue, so T is const int&, param's type is also const int&
f(rx);                   // rx is lvalue, so T is const int&, param's type is also const int&
f(27);                   // 27 is rvalue, so T is int, param's type is therefore int&&
```
* Case 3: ParamType is Neither a Pointer nor a Reference
```
ignore the reference part. const, ignore that, too. If it’s volatile, also ignore. 

int x = 27;          // as before
const int cx = x;    // as before
const int& rx = x;   // as before
void someFunc(int, double);

f(x);                // T's and param's types are both int
f(cx);               // T's and param's types are again both int
f(rx);               // T's and param's types are still both int
f(someFunc);         // param deduced as ptr-to-func; type is void (*)(int, double)
```

### Things to Remember
* During template type deduction, arguments that are references are treated as non-references, i.e., their reference-ness is ignored.

* When deducing types for universal reference parameters, lvalue arguments get special treatment.

* When deducing types for by-value parameters, const and/or volatile arguments are treated as non-const and non-volatile.

* During template type deduction, arguments that are array or function names decay to pointers, unless they’re used to initialize references.