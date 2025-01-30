### Never redefine a function's inherited default parameter value
An object's static type is the type you declare it to have in the program text. Dynamic types, as their name suggests, can change as a program runs, typically through assignments. virtual functions are dynamically bound, but default parameter values are statically bound. Hence you may end up invoking a virtual function defined in a derived class but using a default parameter value from a base class!
### Things to Remember
* Never redefine an inherited default parameter value, because default parameter values are statically bound, while virtual functions — the only functions you should be overriding — are dynamically bound.
