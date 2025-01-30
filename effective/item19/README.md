### Treat class design as type design

In C++, you should therefore approach class design with the same care that language designers lavish on the design of the language's built-in types. Virtually every class requires that you confront the following questions

*  How should objects of your new type be created and destroyed?
* How should object initialization differ from object assignment? 
* What does it mean for objects of your new type to be passed by value?
* What are the restrictions on legal values for your new type?
* Does your new type fit into an inheritance graph?
* What kind of type conversions are allowed for your new type?
* What operators and functions make sense for the new type?
* What standard functions should be disallowed?
* Who should have access to the members of your new type?
* What is the “undeclared interface” of your new type? 
* How general is your new type?
* Is a new type really what you need?

Example is about Implicit and Explicit operations.

#### THINGS TO REMEMBER
* Class design is type design. Before defining a new type, be sure to consider all the issues discussed in this Item.