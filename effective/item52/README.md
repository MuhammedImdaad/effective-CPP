### Write placement delete if you write placement new
 Widget *pw = new Widget;

For above, two function calls take place: one to operator new to allocate memory, a second to Widget's default constructor. Suppose that the first call succeeds, but the second call results in an exception being thrown. In that case, the memory allocation performed in step 1 must be undone. The responsibility for undoing step 1 must therefore fall on the C++ runtime system. When an operator new function takes extra parameters (other than the mandatory size_t argument), that function is known as a placement version of new. 

void* operator new(std::size_t, void *pMemory) throw();   // "placement new

The rule is simple: if an operator new with extra parameters isn't matched by an operator delete with the same extra parameters, `no` operator delete will be called if a memory allocation by the new needs to be undone. Incidentally, because member function names hide functions with the same names in outer scopes (see Item 33), you need to be careful to avoid having class-specific news hide other news (including the normal versions) that your clients expect.
### Things to Remember
* When you write a placement version of operator new, be sure to write the corresponding placement version of operator delete. If you don't, your program may experience subtle, intermittent memory leaks.

* When you declare placement versions of new and delete, be sure not to unintentionally hide the normal versions of those functions.
