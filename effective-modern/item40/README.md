## Use std::atomic for concurrency, volatile for special memory
Once a `std::atomic` object has been constructed, operations on it behave as if they were inside a mutex-protected critical section, but the operations are generally implemented using special machine instructions that are more efficient than would be the case if a mutex were employed. Code using `volatile` guarantees virtually nothing in a multithreaded context.    
As a general rule, compilers are permitted to reorder unrelated assignments. Even if compilers don’t reorder them, the underlying hardware might do it. However, the use of `std::atomic`s imposes restrictions on how code can be reordered. `Volatile` doesn’t impose the same code reordering restrictions. `Volatile` is useful for telling compilers that they’re dealing with memory that doesn’t behave normally. For normal memory operations, compiler can optimize the generated code by elimination techniques. 
```
x = 10;               // write x, optimized away
x = 20;               // write x again 
```
Such optimizations are valid only if memory behaves normally. “Special” memory doesn’t. Probably the most common kind of special memory is memory used for memory-mapped I/O. Locations in such memory actually communicate with peripherals. If x corresponds to the control port for a radio transmitter, it could be that the code is issuing commands to the radio, and the value 10 corresponds to a different command from the value 20. Optimizing out the first assignment would change the sequence of commands sent to the radio.     
`volatile` is the way we tell compilers that we’re dealing with special memory. Its meaning to compilers is “Don’t perform any optimizations on operations on this memory.
```
volatile int x;
```

The situation should thus be clear:
* `std::atomic` is useful for concurrent programming, but not for accessing special memory.
* `volatile` is useful for accessing special memory, but not for concurrent programming.

Because `std::atomic` and `volatile` serve different purposes, they can even be used together:
```
volatile std::atomic<int> vai;    // operations on vai are
                                  // atomic and can't be
                                  // optimized away
```
This could be useful if `vai` corresponded to a memory-mapped I/O location that was concurrently accessed by multiple threads.

### THINGS TO REMEMBER
* std::atomic is for data accessed from multiple threads without using mutexes. It’s a tool for writing concurrent software.
* volatile is for memory where reads and writes should not be optimized away. It’s a tool for working with special memory.