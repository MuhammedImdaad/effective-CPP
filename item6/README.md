 ### Explicitly disallow the use of compiler-generated functions you do not want

To remove the copy constructor and copy assignment, declare those member functions private and deliberately dont implement them.
However in C++11 we can use the delete operator for this task.