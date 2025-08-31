## Prefer task-based programming to thread-based
One of C++11’s great triumphs is the incorporation of concurrency into the language and library. For the first time in C++’s history, programmers can write multithreaded programs with standard behavior across all platforms. 

Three meanings of “thread” in concurrent C++ software:
1. Hardware threads - threads in CPU core
2. Software threads - also known as OS threads or system threads. schedules for execution on hardware threads. 
3. std::threads - objects in a C++ process that act as handles to underlying software threads.

Software threads are a limited resource. Well-written software must somehow deal with this possibility. Even if you don’t run out of threads, you can have trouble with oversubscription. Avoiding oversubscription is difficult. Your life will be easier if you dump these problems on somebody else, and using `std::async` does exactly that:
```
std::future<void> f = std::async(learning); 
```
The function object passed to `std::async` is considered a task. This call shifts the thread management responsibility to the implementer of the C++ Standard Library. It permits the scheduler to arrange for the specified function (in this example, learning) to be run on the thread requesting learning's result. During these allocations, `std::async` and the runtime scheduler will confront load-balancing issues instead of you. When you program directly with `std::threads`, you assume the burden of dealing with thread exhaustion, oversubscription, and load balancing yourself. `Compared to thread-based programming, a task-based design spares you the travails of manual thread management. `

A more fundamental difference between thread-based and task-based programming is the higher level of abstraction that task-based embodies. Nevertheless, there are some situations where using threads directly may be appropriate:
* You need access to the API of the underlying threading implementation.
* You need to and are able to optimize thread usage for your application
* You need to implement threading technology beyond the C++ concurrency API     

These are uncommon cases, however. Most of the time, you should choose task-based designs instead of programming with threads.
### THINGS TO REMEMBER
* The std::thread API offers no direct way to get return values from asynchronously run functions, and if those functions throw, the program is terminated.
* Thread-based programming calls for manual management of thread exhaustion, oversubscription, load balancing, and adaptation to new platforms.
* Task-based programming via std::async with the default launch policy handles most of these issues for you.