## Prefer std::make_unique and std::make_shared to direct use of new
std::make_unique and std::make_shared are two of the three make functions. The third make function is std::allocate_shared. It acts just like std::make_shared, except its first argument is an allocator object to be used for the dynamic memory allocation.
* First reason - derive type

the versions using make functions allow us to use `auto` as it repeat the type being created. 
```
    std::unique_ptr<Widget> ptr1{new Widget{10}};
    auto ptr2{std::make_unique<Widget>(20)};

    std::shared_ptr<Widget> ptr3{new Widget{30}};
    auto ptr4 = std::make_shared<Widget>(40);
```

* The second reason - exception safety. 
```
processWidget(std::shared_ptr<Widget>(new Widget), computePriority()); 
``` 

compilers may emit code to execute the operations in this order: Perform “new Widget”. Execute computePriority. Run std::shared_ptr constructor. If such code is generated and, at runtime, computePriority produces an exception, the dynamically allocated Widget from Step 1 will be leaked, because it will never be stored in the std::shared_ptr that’s supposed to start managing it in Step 3.

``` 
processWidget(std::make_shared<Widget>(), computePriority());
```

* Third - improved efficiency.  

``std::shared_ptr<Widget> spw(new Widget);``

Every std::shared_ptr points to a control block. Memory for this control block is allocated in the std::shared_ptr constructor. Direct use of `new`, then, requires one memory allocation for the Widget and a second allocation for the control block. If std::make_shared is used instead,
one allocation suffices. That’s because std::make_shared allocates a single chunk of memory to hold both the Widget object and the control block. This optimization reduces the static size of the program, because the code contains only one memory allocation call, and it increases the speed of the executable code.

however, this Item’s guidance is to prefer the make functions, not to rely on them exclusively. That’s because there are circumstances where they can’t or shouldn’t be used. For an example, none of the make functions permit the specification of custom deleters. 
Lastly unless you have a compelling reason for doing otherwise, using a `make` function is what you should do.
### THINGS TO REMEMBER
* Compared to direct use of `new`, `make` functions eliminate source code duplication, improve exception safety, and, for std::make_shared and std::allocate_shared, generate code that’s smaller and faster.
* Situations where use of `make` functions is inappropriate include the need to specify custom deleters and a desire to pass braced initializers.
* For std::shared_ptrs, additional situations where `make` functions may be ill-advised include (1) classes with custom memory management and (2) systems with memory concerns, very large objects, and std::weak_ptrs that outlive the corresponding std::shared_ptrs.