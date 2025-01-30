### Adhere to convention when writing new and delete
Item 50 explains when you might want to write your own versions of operator new and operator delete, but it doesn't explain the conventions you must follow when you do it. Operator new actually tries to allocate memory more than once, calling the new-handling function after each failure. The assumption here is that the new-handling function might be able to do something to free up some memory. Only when the pointer to the new-handling function is null does operator new throw an exception. Operator delete should follow C++ guarantee it's always safe to delete the null pointer. Below is a conventional operator new. 

```
void * operator new(std::size_t size) throw(std::bad_alloc)
{                                      // your operator new might take      
                                       // additional params
  using namespace std;                 

  if (size == 0) {                     // handle 0-byte requests
    size = 1;                          // by treating them as
  }                                    // 1-byte requests

  while (true) {
   attempt to allocate size bytes;

    if (the allocation was successful)
       return (a pointer to the memory);

    // allocation was unsuccessful; find out what the
    // current new-handling function is

    new_handler globalHandler = set_new_handler(0); //returns current Handler
    set_new_handler(globalHandler);

    if (globalHandler) 
        (*globalHandler)();
    else 
        throw std::bad_alloc();
  }
}
```
### Things to Remember
* operator new should contain an infinite loop trying to allocate memory, should call the new-handler if it can't satisfy a memory request, and should handle requests for zero bytes. Class-specific versions should handle requests for larger blocks than expected.

* operator delete should do nothing if passed a pointer that is null. Class-specific versions should handle blocks that are larger than expected.