 ### Handle assignment to self in operator=.

The traditional way to prevent this error is to check for assignment to self via an identity test at the top of operator=:. This example represent the approach scott mayers suggest to avoid self assignment and exception handling at the same time.

#### THINGS TO REMEMBER
* Make sure operator= is well-behaved when an object is assigned to itself. Techniques include comparing addresses of source and target objects, careful statement ordering, and copy-and-swap.

* Make sure that any function operating on more than one object behaves correctly if two or more of the objects are the same.