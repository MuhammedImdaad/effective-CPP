## Consider void futures for one-shot event communication
For an event flow where a task need to tell another, asynchronously running task that a particular event has occurred, because the second task can’t proceed until the event has taken place, what’s the best way for this kind of (detect-react) inter-thread communication to take place?
    
An obvious approach is to `use a condition variable (condvar)`. Calling wait on the condvar, must lock a mutex through a std::unique_lock object beforehand. Issue with this approach is what’s sometimes termed a code smell.
If the detecting task notifies the condvar before the reacting task waits, the reacting task will hang. In order for notification of a condvar to wake another task, the other task must be waiting on that condvar.
The wait statement also fails to account for spurious wakeups.   
Next trick is `a shared boolean flag`. This approach suffers from none of the drawbacks of the condvar-based design. However it is far from good because of the cost of polling in the reacting task. Combine the condvar and flag-based designs, approach works, but it doesn’t seem terribly clean.

An alternative is to avoid condition variables, mutexes, and flags by `having the reacting task wait on a future that’s set by the detecting task`. The design is simple. The detecting task has a `std::promise` object (the writing end of the communications channel), and the reacting task has a corresponding `future` (one-one). A `std::promise` may be set only once. The communications channel between a `std::promise` and a `future` is a one-shot mechanism: it can’t be used repeatedly. However it can be extended to suspend and then unsuspend not just one reacting task, but many (one-many). Each reacting thread needs its own copy of the `std::shared_future` that refers to the shared state. 
### THINGS TO REMEMBER
* For simple event communication, condvar-based designs require a superfluous mutex, impose constraints on the relative progress of detecting and reacting tasks, and require reacting tasks to verify that the event has taken place.
* Designs employing a flag avoid those problems, but are based on polling, not blocking.
* A condvar and flag can be used together, but the resulting communications mechanism is somewhat stilted.
* Using std::promises and futures dodges these issues, but the approach uses heap memory for shared states, and it’s limited to one-shot communication.