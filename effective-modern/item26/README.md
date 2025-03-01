## Avoid overloading on universal references
```template<typename T>
void logAndAdd(T&& name);
void logAndAdd(int idx);

short nameIdx;
logAndAdd(nameIdx); //calls universal 
```

The one taking a universal reference can deduce T to be short, thus yielding an exact match. The overload with an int parameter can match the short argument only with a promotion. As per the normal overload resolution rules, an exact match beats a match with a promotion, so the universal reference overload is invoked. Functions taking universal references are the greediest functions in C++. They instantiate to create exact matches for almost any type of argument. 

```
class Person {
public:
  template<typename T>              // perfect forwarding ctor
  explicit Person(T&& n)
  : name(std::forward<T>(n)) {}

  explicit Person(int idx);         // int ctor
  Person(const Person& rhs);        // copy ctor
                                    // (compiler-generated)
  Person(Person&& rhs);             // move ctor
                                    // (compiler-generated)
};

Person p("Nancy");
auto cloneOfP(p);                   // create new Person from non-const p;
                                    // this won't compile!
```

Compilers are sworn to uphold the rules of C++, and the rules of relevance here are the ones governing the resolution of calls to overloaded functions. Hence compilers will generate a call to the better-matching function. “Copying” non-const lvalues of type Person is thus handled by the perfect-forwarding constructor, not the copy constructor.

overloading on universal reference parameters is something you should avoid if at all possible.
### THINGS TO REMEMBER
* Overloading on universal references almost always leads to the universal reference overload being called more frequently than expected.
* Perfect-forwarding constructors are especially problematic, because they’re typically better matches than copy constructors for non-const lvalues, and they can hijack derived class calls to base class copy and move constructors.