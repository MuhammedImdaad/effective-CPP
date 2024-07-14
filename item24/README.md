### Declare non-member functions when type conversions should apply to all parameters 
Make function a non-member function, thus allowing compilers to perform implicit type conversions on all arguments.
#### THINGS TO REMEMBER
* If you need type conversions on all parameters to a function (including the one pointed to by the `this` pointer), the function must be a non-member.