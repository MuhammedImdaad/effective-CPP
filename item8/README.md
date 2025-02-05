## Prefer nullptr to 0 and NULL
std::nullptr_t is defined to be the type of nullptr. The type std::nullptr_t implicitly converts to all raw pointer types, and that’s what makes nullptr act as if it were a pointer of all types. When you want to refer to a null pointer, use nullptr, not 0 or NULL.    
The fact that template type deduction deduces the “wrong” types for 0 and NULL (i.e., their true types, rather than their fallback meaning as a representation for a null pointer) is the most compelling reason to use nullptr instead of 0 or NULL when you want to refer to a null pointer.
### THINGS TO REMEMBER
* Prefer nullptr to 0 and NULL.

* Avoid overloading on integral and pointer types.