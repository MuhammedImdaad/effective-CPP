## Use std::shared_ptr for shared-ownership resource management
std::shared_ptr is the C++11 way of binding two worlds together. a system that works automatically (like garbage collection), yet applies to all resources and has predictable timing (like destructors). As with garbage collection, clients need not concern themselves with managing the lifetime of pointed-to objects, but as with destructors, the timing of the objects’ destruction is deterministic.   
If a std::shared_ptr sees a reference count of zero after performing a decrement, no more std::shared_ptrs point to the resource, so the std::shared_ptr destroys it. However, the existence of the reference count has performance implications. 
* twice the size of a raw pointer. 
* Memory for the reference count must be dynamically allocated. 
* Increments and decrements of the reference count must be atomic

Move-constructing a std::shared_ptr from another std::shared_ptr sets the source std::shared_ptr to null, and that means that the old std::shared_ptr stops pointing to the resource at the moment the new std::shared_ptr starts. As a result, reference count does not change. Hence Moving std::shared_ptrs is therefore faster than copying them.   
For std::unique_ptr, the type of the deleter is part of the type of the smart pointer. For std::shared_ptr, it’s not. Another difference from std::unique_ptr, specifying a custom deleter doesn’t change the size of a std::shared_ptr object.  
An object’s control block is dynamically set up by the function creating the first std::shared_ptr to the object to store the reference count, allocator and deallocator functions.   
Constructing more than one std::shared_ptr from a single raw pointer gives undefined behavior. Therefore, there are at least two lessons regarding std::shared_ptr use here. 
* Try to avoid passing raw pointers to a std::shared_ptr constructor.
* If you must pass a raw pointer to a std::shared_ptr constructor, pass the result of new directly. 

An especially surprising way that using raw pointer variables as std::shared_ptr constructor arguments can lead to multiple control blocks involves the `this` pointer. `std::enable_shared_from_this` is a template for a base class you inherit from if you want a class managed by std::shared_ptrs to be able to safely create a std::shared_ptr from a `this` pointer.     
Std::shared_ptrs also incurs the cost of the machinery for the virtual function used by the control block. Thus dynamically allocated control blocks, arbitrarily large deleters and allocators, virtual function machinery, and atomic reference count manipulations can take up performance. But for the functionality they provide, std::shared_ptrs exact a very reasonable cost.   
`In all cases, if exclusive ownership will do or even may do, "std::unique_ptr" is a better choice.` upgrading from std::unique_ptr to std::shared_ptr is easy, however the reverse is not true.    
Something else std::shared_ptrs can’t do is work with arrays, in yet another difference from std::unique_ptr. Given the variety of C++11 alternatives to built-in arrays (e.g., std::array, std::vector, std::string), declaring a smart pointer to a dumb array is almost always a sign of bad design.
### THINGS TO REMEMBER
* std::shared_ptrs offer convenience approaching that of garbage collection for the shared lifetime management of arbitrary resources.
* Compared to std::unique_ptr, std::shared_ptr objects are typically twice as big, incur overhead for control blocks, and require atomic reference count manipulations.
* Default resource destruction is via delete, but custom deleters are supported. The type of the deleter has no effect on the type of the std::shared_ptr.
* Avoid creating std::shared_ptrs from variables of raw pointer type.