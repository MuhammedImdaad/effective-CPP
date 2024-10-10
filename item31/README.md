### Minimize compilation dependencies between files
* Declaration - simple stating such thing exist(a class)
* Definition - defining such things (methods and attributes)
* Implementation - implementing such things (method definitions)

To improve build times and reduce unnecessary dependencies, limit how much one file depends on changes in another.  If any of the header files are changed, or if any of the header files they depend on changes, the file containing the class must be recompiled, as must any files that use the class. One way to solve this is using Forward Declarations Instead of Includes. Difficulty with forward-declaring everything has to do with the need for compilers to know the size of objects during compilation.

The key to this separation is replacement of dependencies on definitions with dependencies on declarations. That's the essence of minimizing compilation dependencies: make your header files self-sufficient whenever it's practical, and when it's not, depend on declarations in other files, not definitions. Everything else flows from this simple design strategy.

* Avoid using objects when object references and pointers will do
* Depend on class declarations instead of class definitions whenever you can
    * Note that you never need a class definition to declare a function using that class, not even if the function passes or returns the class type by value
* Provide separate header files for declarations and definitions

In the example, main is a client of widget. Widget is using the pimpl ideology. Hence all the implementation changes are freequently done in WidgetImpl class. Widget has not included the WidgetImpl (forward declared), however since it only uses a pointer to implementation, compiler can allocate memory for the widget object in the main without knowing the WidgetImpl definition. Now when you make changes for WidgetImpl definition, main need not to be recompiled again!

Classes that employ the pimpl idiom are often called Handle classes. An alternative to the Handle class approach is to make a special kind of abstract base class called an Interface class. Like clients of Handle classes, clients of Interface classes need not recompile unless the Interface class's interface is modified. Handle classes and Interface classes decouple interfaces from implementations, thereby reducing compilation dependencies between files.

#### THINGS TO REMEMBER
* The general idea behind minimizing compilation dependencies is to depend on declarations instead of definitions. Two approaches based on this idea are Handle classes and Interface classes.
* Library header files should exist in full and declaration-only forms. This applies regardless of whether templates are involved.