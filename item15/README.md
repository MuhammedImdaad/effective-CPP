### Provide access to raw resources in resource-managing classes
You need a way to convert an object of the RAII class into the raw resource it contains. There are two general ways to do it: explicit conversion and implicit conversion. The decision about whether to offer explicit conversion from an RAII class to its underlying resource (e.g., via a get member function) or whether to allow implicit conversion is one that depends on the specific task. Often, an explicit conversion function like get() is the preferable path.
Example is about explicit and implicit conversion operators. 

#### THINGS TO REMEMBER
* APIs often require access to raw resources, so each RAII class should offer a way to get at the resource it manages.

* Access may be via explicit conversion or implicit conversion. In general, explicit conversion is safer, but implicit conversion is more convenient for clients.