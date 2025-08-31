## Make std::threads unjoinable on all paths
Every std::thread object is in one of two states: `joinable` or `unjoinable`.   
A joinable std::thread corresponds a thread, that is or could be running, that’s blocked or waiting to be scheduled, that have run to completion.   
An unjoinable std::thread is a thread that is, default-constructed, std::thread object that have been moved from, std::thread that have been joined, std::thread that have been detached.

One reason a std::thread’s joinability is important is that `if the destructor of a joinable thread is invoked, execution of the program is terminated!` You might wonder why the std::thread destructor behaves this way. It’s because the two other obvious options are arguably worse.    
An implicit join - performance anomalies        
An implicit detach - may lead to undefined behaviour        
The Standardization Committee thus essentially banned it by specifying that destruction of a joinable thread causes program termination.

Therefore you need to ensure that if you use a std::thread object, it’s made unjoinable on every path out of the scope in which it’s defined. Any time you want to perform some action along every path out of a block, the normal approach is to put that action in the destructor of a local object. Such objects are known as RAII objects. 

Given a choice between undefined behavior (which detach would get us), program termination (which use of a raw std::thread would yield), or performance anomalies, performance anomalies seems like the best of a bad lot.      
C++20 introduced std::jthread (joining thread) which automatically joins in its destructor.
### THINGS TO REMEMBER
* Make std::threads unjoinable on all paths.
* join-on-destruction can lead to difficult-to-debug performance anomalies.
* detach-on-destruction can lead to difficult-to-debug undefined behavior.
* Declare std::thread objects last in lists of data members.