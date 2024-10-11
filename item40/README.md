### Use multiple inheritance judiciously
When MI enters the designscape, it becomes possible to inherit the same name (e.g., function, typedef, etc.) from more than one base class. That leads to new opportunities for ambiguity. To resolve the ambiguity, you must specify which base class's function to call. 

Multiple inheritance can lead to what is sometimes known as the “deadly MI diamond". See the example. 
you must make the class with the data (File) a virtual base class. To do that, you have all classes that immediately inherit from it use virtual inheritance. However virtual inheritance comes with its own costs.

The responsibility for initializing a virtual base is borne by the most derived class in the hierarchy. Implications of this rule include
* classes derived from virtual bases that require initialization must be aware of their virtual bases, no matter how far distant the bases are
* when a new derived class is added to the hierarchy, it must assume initialization responsibilities for its virtual bases (both direct and indirect).
#### THINGS TO REMEMBER
* Multiple inheritance is more complex than single inheritance. It can lead to new ambiguity issues and to the need for virtual inheritance.

* Virtual inheritance imposes costs in size, speed, and complexity of initialization and assignment. It's most practical when virtual base classes have no data.

* Multiple inheritance does have legitimate uses. One scenario involves combining public inheritance from an Interface class with private inheritance from a class that helps with implementation.