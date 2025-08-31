## Avoid default capture modes
Lambdas really make C++ a more pleasant programming language.
lambda vocabulary,
* lambda expression - expression that is part of the source code [capture] \(arguments) {body}
* closure - the runtime object created by a lambda
* closure class - class generated from the lambda expression, from which a closure is instantiated

Long-term, it’s simply better software engineering to explicitly list the local variables and parameters that a lambda depends on. 
There are two default capture modes in C++11: by-reference and by-value. A by-reference capture causes a closure to contain a reference to a local variable or to a parameter that’s available in the scope where the lambda is defined. If the lifetime of a closure created from that lambda exceeds the lifetime of the local variable or parameter, the reference in the closure will dangle. Thus undefined behavior (Crash, garbage values, Work correctly by chance). With an explicit capture, it’s easier to see that the viability of the lambda is dependent on divisor’s lifetime.  
Captures apply only to non-static local variables (including parameters) visible in the scope where the lambda is created. default by-value (=) capture, captures the object’s `this` pointer. Since it captures `this`, member attributes and static local variables can be used inside lambdas, but they won't be captured. Any change in those variables will change the closure, mimicing default by reference capture behaviour which is contradictory to by-value capture. Also the viability of the closures arising from this lambda is tied to the lifetime of the object whose `this` pointer they contain a copy of (ref). If you stay away from default by-value capture clauses, you eliminate the risk of your code being misread in this way.   

closure class is essentially a class with overloaded `operator ()` method. So the amount of storage depends on the capture variables.  
* Capture by value: Size is the sum of the sizes of the captured variables.
* Capture by reference: Size is the sum of the sizes of the pointers to the captured variables.
### THINGS TO REMEMBER
* Default by-reference capture can lead to dangling references.
* Default by-value capture is susceptible to dangling pointers (especially `this`), and it `misleadingly suggests that lambdas are self-contained.`