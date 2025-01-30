### Understand when it makes sense to replace new and delete
The topic of this Item is knowing when it can make sense to replace the default versions of new and delete, either globally or on a per-class basis. Writing a custom memory manager that almost works is pretty easy. Writing one that works well is a lot harder. An open source allocator named Pool library from Boost library offers allocators tuned for one of the most common situations in which custom memory management is helpful. Allocation of a large number of small objects.

* To detect usage errors
* To collect statistics about the use of dynamically allocated memory
* To increase the speed of allocation and deallocation
* To reduce the space overhead of default memory management
* To compensate for suboptimal alignment in the default allocator.
* To cluster related objects near one another
* To obtain unconventional behavior
### Things to Remember
* There are many valid reasons for writing custom versions of new and delete, including improving performance, debugging heap usage errors, and collecting heap usage information.
