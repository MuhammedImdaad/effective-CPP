### Think carefully about copying behavior in resource-managing classes
The basic structure of a resource-managing class is dictated by the RAII principle that resources are acquired during construction and released during destruction. what should happen when an RAII object is copied? Most of the time, you'll want to choose one of the following possibilities. 
* Prohibit copying
* Reference-count the underlying resource
* Copy the underlying resource
* Transfer ownership of the underlying resource

#### THINGS TO REMEMBER
* Copying an RAII object entails copying the resource it manages, so the copying behavior of the resource determines the copying behavior of the RAII object.
* Common RAII class copying behaviors are disallowing copying and performing reference counting, but other behaviors are possible.