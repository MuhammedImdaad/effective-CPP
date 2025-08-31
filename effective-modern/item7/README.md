## Distinguish between () and {} when creating objects
As a general rule, initialization values may be specified with parentheses, an equals sign, or braces. The “confusing mess” lobby points out that the use of an equals sign for initialization often misleads C++ newbies into thinking that an assignment is taking place, even though it’s not.
C++11 introduces `uniform initialization`: a single initialization syntax that can, at least in concept, be used anywhere and express everything.
As such out of C++’s three ways to designate an initializing expression, only braces can be used everywhere.

Braces can also be used to `specify default initialization values for non-static data members`. This capability—new to C++11—is shared with the “=” initialization syntax. braced initialization is that it warns implicit narrowing conversions among built-in types. Another noteworthy characteristic of braced initialization is its `immunity to C++’s most vexing parse`. The most vexing parse most frequently afflicts developers when they want to default-construct an object, but inadvertently end up declaring a function instead! With all the positives, why isn’t this Item entitled something like “Prefer braced initialization syntax”?

The `drawback` is the relationship among braced initializers, std::initializer_lists in constructor arguments, and constructor overload resolution.
Mind; Empty braces mean no arguments, not an empty std::initializer_list. Calls using the braced initialization syntax `strongly` prefer the overloads taking std::initializer_lists. Only if there’s no way to convert the types of the arguments in a braced initializer to the type in a std::initializer_list do compilers fall back on normal overload resolution. Another area: If you create a std::vector of a numeric type (e.g., a std::vector<int>) and you pass two arguments to the constructor, whether you enclose those arguments in parentheses or braces makes a tremendous difference.

There are two primary takeaways from this discussion. First, `as a class author`, you need to be aware that if your set of overloaded constructors includes one or more functions taking a std::initializer_list, client code using braced initialization may see only the std::initializer_list overloads. The second lesson is that `as a class client`, you must choose carefully between parentheses and braces when creating objects.

### THINGS TO REMEMBER
* Braced initialization is the most widely usable initialization syntax, it prevents narrowing conversions, and it’s immune to C++’s most vexing parse.
* During constructor overload resolution, braced initializers are matched to std::initializer_list parameters if at all possible, even if other constructors offer seemingly better matches.

* An example of where the choice between parentheses and braces can make a significant difference is creating a std::vector<numeric type> with two arguments.

* Choosing between parentheses and braces for object creation inside templates can be challenging.

* There’s no consensus that either approach is better than the other, so advice is to pick one and apply it consistently.