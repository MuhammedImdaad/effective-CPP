## Consider emplacement instead of insertion
```
std::vector<std::string> vs;         // container of std::string

vs.push_back("xyzzy");               // add string literal
```
Here argument you’re passing to `push_back` is not of the type held by the container. Code above doesn’t make just one constructor call. It makes two. And it calls the std::string destructor, too.
There is a way to do exactly what is needed for maximal efficiency in the call to `push_back`. It’s to not to call `push_back`. `push_back` is the wrong function. The function you want is `emplace_back`. `emplace_back` does exactly what we desire: it uses whatever arguments are passed to it to construct a std::string directly inside the std::vector. No temporaries are involved:    
What makes it possible for emplacement functions to outperform insertion functions is their more flexible interface. Insertion functions take objects to be inserted, while `emplacement functions take constructor arguments for objects to be inserted`. This difference permits emplacement functions to avoid the creation and destruction of temporary objects that insertion functions can necessitate.   
The primary advantage of emplacement over insertion is that temporary objects are neither created nor destroyed. Emplacement functions can thus do everything insertion functions can. They sometimes do it more efficiently, and, at least in theory, they should never do it less efficiently. So why not use them all the time? There’s a heuristic that can help you identify situations where emplacement functions are most likely to be worthwhile.      
`If all the following are true`, emplacement will almost certainly outperform insertion:
* The value being added is constructed into the container, not assigned.
* The argument type(s) being passed differ from the type held by the container.
* The container is unlikely to reject the new value as a duplicate.

Satisfying all the criteria above, `emplate_back` can run faster than the corresponding calls to `push_back`.
```
vs.emplace_back("xyzzy");   // construct new value at end of
                            // container; don't pass the type in
                            // container; don't use container
                            // rejecting duplicates

vs.emplace_back(50, 'x');   // same as above
```
When deciding whether to use emplacement functions, two other issues are worth keeping in mind. The first regards resource management. A second is their interaction with explicit constructors.
### THINGS TO REMEMBER
* In principle, emplacement functions should sometimes be more efficient than their insertion counterparts, and they should never be less efficient.
* In practice, they’re most likely to be faster when (1) the value being added is constructed into the container, not assigned; (2) the argument type(s) passed differ from the type held by the container; and (3) the container won’t reject the value being added due to it being a duplicate. 
* Emplacement functions may perform type conversions that would be rejected by insertion functions.