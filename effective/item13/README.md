### Use objects to manage resources

Two critical aspects of using objects to manage resources.
* Resources are acquired and immediately turned over to resource-managing objects.
* Resource-managing objects use their destructors to ensure that resources are released.

This item is what the motivaion behind C++11 Smart Pointers.

#### THINGS TO REMEMBER
* To prevent resource leaks, use RAII objects that acquire resources in their constructors and release them in their destructors.

* Two commonly useful RAII classes are tr1::shared_ptr and auto_ptr. tr1::shared_ptr is usually the better choice, because its behavior when copied is intuitive. Copying an auto_ptr sets it to null.