 ### Store newed objects in smart pointers in standalone statements

processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority())

If compilers choose to perform evaluation order from something that may allow them to generate more efficient code, we may end up with this sequence of operations

Execute “new Widget”.
Call priority.
Call the tr1::shared_ptr constructor.

if the call to priority yields an exception, the pointer returned from “new Widget” will be lost. The way to avoid problems like this is simple: use a separate statement to create the Widget and store it in a smart pointer, then pass the smart pointer to processWidget:

#### THINGS TO REMEMBER
* Store newed objects in smart pointers in standalone statements. Failure to do this can lead to subtle resource leaks when exceptions are thrown.