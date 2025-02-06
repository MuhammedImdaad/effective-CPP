## Prefer scoped enums to unscoped enums
As a general rule, declaring a name inside curly braces limits the visibility of that name to the scope defined by the braces. Not so for the enumerators declared in C++98-style enums. Because scoped enums are declared via “enum class”, they’re sometimes referred to as enum classes.  
Enumerators for unscoped enums implicitly convert to integral types.    
scoped enums may be forward-declared. C++98 supports only enum definitions (where all enumerators are listed); enum declarations are not allowed.   
the underlying type for a scoped enum is always known, and for unscoped enums, you can specify it. By default, the underlying type for scoped enums is int.

It may surprise you to hear that there’s at least one situation where unscoped enums may be useful. That’s when referring to fields within C++11’s std::tuples.
### THINGS TO REMEMBER
* C++98-style enums are now known as unscoped enums.

* Enumerators of scoped enums are visible only within the enum. They convert to other types only with a cast.

* Both scoped and unscoped enums support specification of the underlying type. The default underlying type for scoped enums is int. Unscoped enums have no default underlying type.

* Scoped enums may always be forward-declared. Unscoped enums may be forward-declared only if their declaration specifies an underlying type.