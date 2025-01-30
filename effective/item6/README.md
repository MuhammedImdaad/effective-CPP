 ### Explicitly disallow the use of compiler-generated functions you do not want

To remove the copy constructor and copy assignment, declare those member functions private and deliberately dont implement them.
However in C++11 we can use the delete operator for this task.

#### THINGS TO REMEMBER
* To disallow functionality automatically provided by compilers, declare the corresponding member functions private and give no implementations. Using a base class like Uncopyable is one way to do this.