## Be aware of varying thread handle destructor behavior
The destructor for a future sometimes behaves as if it did an implicit join, sometimes as if it did an implicit detach, and sometimes neither. `It never causes program termination`.    
Future is one end of a communications channel through which a callee transmits a result to a caller. The callee (usually running asynchronously) writes the result of its computation into the communications channel (typically via a std::promise object), and the caller reads that result using a future. 
```
Caller (future) <------------ Callee (promise)
```
But where is the callee’s result stored? can’t be stored in the callee’s std::promise, can’t be stored in the caller’s future, either. Because neither objects associated with the callee nor objects associated with the caller, suitable places to store the callee’s result is in a location outside both. This location is known as the `shared state`. The existence of the `shared state` is important, because the behavior of a future’s destructor is determined by the `shared state` associated with the future. 

What we’re really dealing with is a simple `normal` behavior and one lone exception to it. The normal behavior is that a future’s destructor destroys the future object. It just destroys the future’s data members. The exception to this normal behavior arises only for a future for which `all` of the following apply: 
The destructor for the `last future`, `referring to a shared state` for a `non-deferred task` launched via std::async.     
Only when all of these conditions are fulfilled does a future’s destructor exhibit special behavior, and that behavior is to block until the asynchronously running task completes. If you have a way of knowing that a given future does not satisfy the conditions that trigger the special destructor behavior, you’re assured that that future won’t block in its destructor.
### THINGS TO REMEMBER
* Future destructors normally just destroy the future’s data members.
* The final future referring to a shared state for a non-deferred task launched via std::async blocks until the task completes.