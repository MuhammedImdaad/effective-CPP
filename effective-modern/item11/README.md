## Prefer deleted functions to private undefined ones
In C++98, if you want to suppress use of a member function (the copy constructor, the assignment operator), the C++98 approach is to declare them private and not define them. In C++11, there’s a better way to achieve essentially the same end: use `= delete` to mark the copy constructor and the copy assignment operator as deleted functions.   
Deleted functions may not be used in any way, so even code that’s in member and friend functions will fail to compile if it tries to call it.   
An important advantage of deleted functions is that any function may be deleted, while only member functions may be private.    
Another trick that deleted functions can perform (and that private member functions can’t) is to prevent use of template instantiations that should be disabled.    
The truth is that the C++98 practice of declaring functions private and not defining them was really an attempt to achieve what C++11’s deleted functions actually accomplish.
### THINGS TO REMEMBER
* Prefer deleted functions to private undefined ones.
* Any function may be deleted, including non-member functions and template instantiations.