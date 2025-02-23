## Assume that move operations are not present, not cheap, and not used
Move semantics is truly an important feature. It actually requires to replace expensive copy operations with comparatively cheap moves. The purpose of this Item is to keep your exaggerated expectations grounded.     
For types without explicit support for moving and that don’t qualify for compiler-generated move operations, there is no reason to expect C++11 to deliver any kind of performance improvement over C++98. Even types with explicit move support may not benefit as much as you’d hope. Most of the standard C++ containers, stores its contents on the heap. The existence of the pointer makes it possible to move the contents of an entire container in constant time: just copy the pointer to the container’s contents from the source container to the target, and set the source’s pointer to null. std::array objects lack such a pointer, because the data for a std::array’s contents are stored directly in the std::array object. As such both moving and copying a std::array have linear-time computational complexity.  
There are several scenarios in which C++11’s move semantics do you no good. 
* No move operations: The object to be moved from fails to offer move operations. The move request therefore becomes a copy request.
* Move not faster: The object to be moved from has move operations that are no faster than its copy operations.
* Move not usable: The context in which the moving would take place requires a move operation that emits no exceptions, but that operation isn’t declared noexcept.     

Title of this Item is to assume that move operations are not present, not cheap, and not used. This is typically the case in generic code. Often, however, you know the types your code uses, and you can rely on their characteristics. When that’s the case, you don’t need to make assumptions. 
### THINGS TO REMEMBER
* Assume that move operations are not present, not cheap, and not used.
* In code with known types or support for move semantics, there is no need for assumptions.