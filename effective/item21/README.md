### Don't try to return a reference when you must return an object
Any function returning a reference to a local object is broken. (The same is true for any function returning a pointer to a local object.)

Constructing an object on the heap and returning a reference to it? who will apply delete to the object conjured up by your use of `new`?

Returning a reference to a static object, one defined inside the function? Like all designs employing the use of static objects, this one immediately raises our thread-safety hackles, but that's its more obvious weakness. 

The right way to write a function that must return a new object is to have that function return a new object
#### THINGS TO REMEMBER
* Never return a pointer or reference to a local stack object, a reference to a heap-allocated object, or a pointer or reference to a local static object if there is a chance that more than one such object will be needed.
