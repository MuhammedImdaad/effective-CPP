### Never redefine an inherited non-virtual function
If you do so, determining factor for function call will have nothing to do with the object itself, but with the declared type of the pointer that points to it. That violated the `D is a B` inheritence relationship.

class D : public B
* pD->f()
* pB->f()
### Things to Remember
* Never redefine an inherited non-virtual function
