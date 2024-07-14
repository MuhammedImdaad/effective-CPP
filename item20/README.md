 ### Prefer pass-by-reference-to-const to pass-by-value

bool validateStudent(const Student& s);

This is much more efficient: no constructors or destructors are called, because no new objects are being created. The const in the revised parameter declaration is important. In pass-by-value, callers knew that they were shielded from any changes the function might make to the object they passed in. Now that the object is being passed by reference, it's necessary to also declare it const, because otherwise callers would have to worry about the function making changes to the object they passed in.

Passing parameters by reference also avoids the slicing problem.

In general, the only types for which you can reasonably assume that pass-by-value is inexpensive are built-in types and STL iterator and function object types. 

If you peek under the hood of a C++ compiler, you'll find that references are typically implemented as pointers, so passing something by reference usually means really passing a pointer.

#### THINGS TO REMEMBER
* Prefer pass-by-reference-to-const over pass-by-value. It's typically more efficient and it avoids the slicing problem.

* The rule doesn't apply to built-in types and STL iterator and function object types. For them, pass-by-value is usually appropriate.