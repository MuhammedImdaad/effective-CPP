### Understand the behavior of the new-handler
When operator new is unable to fulfill a memory request, it calls the `single instance` new-handler function repeatedly until it can find enough memory. Hence a well-designed new-handler function must do one of the following. 
* Make more memory available
* Install a different new-handler
* Deinstall the new-handler
* Throw an exception
* Not return

In the example, the base class part of the design lets derived classes inherit the set_new_handler and operator new functions they all need, while the template part of the design ensures that each inheriting class gets a different currentHandler data member. NewHandlerSupport template never uses its type parameter T. It doesn't need to. All we need is a different copy of NewHandlerSupport — in particular, its static data member currentHandler — for each `class` that inherits from NewHandlerSupport. The template parameter T just distinguishes one inheriting class from another. The template mechanism itself automatically generates a copy of currentHandler for each T with which NewHandlerSupport is instantiated.

As for Widget inheriting from a templatized base class that takes T as a type parameter, it has a name. It's called the curiously recurring template pattern (CRTP).
#### THINGS TO REMEMBER
* set_new_handler allows you to specify a function to be called when memory allocation requests cannot be satisfied.
* Nothrow new is of limited utility, because it applies only to memory allocation; subsequent constructor calls may still throw exceptions.