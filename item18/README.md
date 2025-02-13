## Use std::unique_ptr for exclusive-ownership resource management
The reasons why a raw pointer is hard to love:
* Declaration doesn’t indicate whether it points to a single object or to an array.
* Missing a path leads to resource leaks, and doing the destruction more than once leads to undefined behavior.
* Dangling pointers arise when objects are destroyed while pointers still point to them.
Smart pointers can do virtually everything raw pointers can, but with far fewer opportunities for error.

If a raw pointer is small enough and fast enough for you, a std::unique_ptr almost certainly is, too. A `non-null` std::unique_ptr always owns what it points to. `Moving` a std::unique_ptr transfers ownership from the source pointer to the destination pointer. Copying a std::unique_ptr isn’t allowed.   
A common use for std::unique_ptr is as a factory function return type for objects. Even more popular as a mechanism for implementing the Pimpl Idiom. std::unique_ptr comes in two forms, one for individual objects (std::unique_ptr<T>) and one for arrays (std::unique_ptr<T[]>). As a result, there’s never any ambiguity about what kind of entity a std::unique_ptr points to.    
One of its most attractive features is that it easily and efficiently converts to a std::shared_ptr. By returning a std::unique_ptr, factories provide callers with the most efficient smart pointer, but they don’t hinder callers from replacing it with its more flexible sibling.
### THINGS TO REMEMBER
* std::unique_ptr is a small, fast, move-only smart pointer for managing resources with exclusive-ownership semantics.
* By default, resource destruction takes place via delete, but custom deleters can be specified. Stateful deleters and function pointers as deleters increase the size of std::unique_ptr objects.
* Converting a std::unique_ptr to a std::shared_ptr is easy.