## Specify std::launch::async if asynchronicity is essential
When you define std::async, what you’re asking to do is requesting that the function to be run in accord with a std::async launch policy. There are two standard policies, 
* std::launch::`async` - policy means that f must be run `asynchronously`, run on a different thread.
* std::launch::`deferred` - policy means that f may run only when `get` or `wait` is called on the future returned by std::async. That is, f’s execution is `deferred` until such a call is made. When `get` or `wait` is invoked, f will execute `synchronously`, the caller will block until f finishes running. If neither `get` nor `wait` is called, f will never run. (not much different to directly calling a function when it is needed!)

std::async’s `default` launch policy, the one it uses if you don’t expressly specify one, it’s these `or-ed` together (`std::launch::async | std::launch::deferred`). The default policy permits f to be run either asynchronously or synchronously.   
Thus stating std::async with the default launch policy has some interesting implications.
* It’s not possible to predict whether f will run concurrently with t, because f might be scheduled to run deferred.
* It’s not possible to predict whether f runs on a thread different from the thread invoking get or wait on fut.
* It may not be possible to predict whether f runs at all, because it may not be possible to guarantee that get or wait will be called on fut along every path through the program.

Using std::async with the default launch policy for a task is fine as long as the following conditions are fulfilled:
* The task need not run concurrently with the thread calling get or wait.
* It doesn’t matter which thread’s thread_local variables are read or written.
* Either there’s a guarantee that get or wait will be called on the future returned by std::async or it’s acceptable that the task may never execute.
* Code using wait_for or wait_until takes the possibility of deferred status into account.

If any of these conditions fails to hold, you probably want to guarantee that std::async will schedule the task for truly asynchronous execution. Thus having a function that acts like std::async, but that automatically uses std::launch::async as the launch policy, is a convenient tool to have around. 
### THINGS TO REMEMBER
* The default launch policy for std::async permits both asynchronous and synchronous task execution.
* This flexibility leads to uncertainty when accessing thread_locals, implies that the task may never execute, and affects program logic for timeout-based wait calls.
* Specify std::launch::async if asynchronous task execution is essential.