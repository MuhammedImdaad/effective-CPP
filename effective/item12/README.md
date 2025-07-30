### Copy all parts of an object

Only two functions copy objects: named copy constructor and copy assignment operator. We'll call these the copying functions. Any time you take it upon yourself to write copying functions for a derived class, you must take care to also copy the base class parts.
When you're writing a copying function, be sure to 
 1. copy all local data members 
 2. invoke the appropriate copying function in all base classes, too.  It will call the base class default constructor otherwise. Do see for you by //comment out.  

If you find that your copy constructor and copy assignment operator have similar code bodies, eliminate the duplication by creating a third member function that both call.

#### THINGS TO REMEMBER
* Copying functions should be sure to copy all of an object's data members and all of its base class parts.
* Don't try to implement one of the copying functions in terms of the other. Instead, put common functionality in a third function that both call.