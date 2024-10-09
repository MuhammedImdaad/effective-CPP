### Understand the ins and outs of inlining

The idea behind an inline function is to replace each call of that function with its code body.

Types of inline:
* Implicit -  define a function inside a class definition. See getAge() in example. 
* explicit - declare an inline function by precede its definition with the inline keyword.

Inline functions must typically be in header files, because most build environments do inlining during compilation. check the commented line in item30.h

inline is a request that compilers may ignore. Initially, don't inline anything, or at least limit your inlining.

constructors and destructors are often worse candidates for inlining! Because usually compiler generated codes ends up in constructors and destructors. 

#### THINGS TO REMEMBER
* Limit most inlining to small, frequently called functions. This facilitates debugging and binary upgradability, minimizes potential code bloat, and maximizes the chances of greater program speed.
* Don't declare function templates inline just because they appear in header files.