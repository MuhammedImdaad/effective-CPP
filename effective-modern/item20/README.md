## Use std::weak_ptr for std::shared_ptr-like pointers that can dangle
std::weak_ptr isn’t a standalone smart pointer. It’s an augmentation of std::shared_ptr. The relationship begins at birth. std::weak_ptrs are typically created from std::shared_ptrs. They point to the same place as the std::shared_ptrs initializing them, but `they don’t affect the reference count` of the object they point to. std::weak_ptrs that dangle are said to have `expired`.   
Often what you desire is a check to see if a std::weak_ptr has expired and, if it hasn’t (if it’s not dangling), to access the object it points to. std::weak_ptrs `lack dereferencing operations`, so there’s no way to write the code. Even if there were, separating the check and the dereference would introduce a race condition. So you need an atomic operation that checks to see if the std::weak_ptr has expired and, if not, gives you access to the object it points to. This is done by creating a std::shared_ptr from the std::weak_ptr.    
std::weak_ptrs can be useful due to the fact that they can detect when they dangle. 
* factory function that produces smart pointers
* the Observer design pattern. 
* child-parent abnormal relationship    

From an efficiency perspective, the std::weak_ptr story is essentially the same as that for std::shared_ptr !. The control block contains a second reference count, one that tallies how many std::weak_ptrs refer to the control block. As long as std::weak_ptrs refer to a control block (the weak count is greater than zero), that control block continue to exist. And as long as a control block exists, the memory containing it remain allocated.
### THINGS TO REMEMBER
* Use std::weak_ptr for std::shared_ptr-like pointers that can dangle.
* Potential use cases for std::weak_ptr include caching, observer lists, and the prevention of std::shared_ptr cycles.