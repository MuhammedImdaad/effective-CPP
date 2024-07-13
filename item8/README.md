 ### Prevent exceptions from leaving destructors

C++ does not like destructors that emit exceptions! There are two primary ways to avoid the trouble.
* Terminate the program 
* Swallow the exception 

If an operation may fail by throwing an exception and there may be a need to handle that exception, the exception has to come from some non-destructor function. That's because destructors that emit exceptions are dangerous, always running the risk of premature program termination or undefined behavior.

#### THINGS TO REMEMBER
* Destructors should never emit exceptions. If functions called in a destructor may throw, the destructor should catch any exceptions, then swallow them or terminate the program.

* If class clients need to be able to react to exceptions thrown during an operation, the class should provide a regular (i.e., non-destructor) function that performs the operation.