### Avoid returning “handles” to object internals
References, pointers, and iterators are all handles (ways to get at other objects), and returning a handle to an object's internals always runs the risk of compromising an object's encapsulation. 

#### THINGS TO REMEMBER
* Avoid returning handles (references, pointers, or iterators) to object internals. It increases encapsulation, helps const member functions act const, and minimizes the creation of dangling handles.
