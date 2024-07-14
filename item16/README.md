 ### Use the same form in corresponding uses of new and delete

When you employ a delete expression (i.e., use delete), two things happen: one or more destructors are called for the memory, then the memory is deallocated (via a function named operator delete).

#### THINGS TO REMEMBER
* If you use [] in a new expression, you must use [] in the corresponding delete expression. If you don't use [] in a new expression, you mustn't use [] in the corresponding delete expression.