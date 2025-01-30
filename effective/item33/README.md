### Avoid hiding inherited names
Names in inner scopes hide (“shadow”) names in outer scopes. The scope of a derived class is nested inside its base class's scope. 

When compilers see the use of a name in a derived class, they have to figure out what it refers to. First they look in the local scope (that of the name). They then search the containing scope, that of the class Derived. They then move on to the next containing scope, that of the base class. Then the search would continue to the namespace(s) containing Base, and finally to the global scope.

In the example, Base::mf1 and Base::mf3 are no longer inherited by Derived when Derived has used the name within (not even an overloaded name). The rationale behind this behavior is that it prevents you from accidentally inheriting overloads from distant base classes when you create a new derived class. That being the case, you'll almost always want to override C++'s default hiding of inherited names. You do it with `using` declarations. A different technique namely, forwarding technique also exist.
#### THINGS TO REMEMBER
* Names in derived classes hide names in base classes. Under public inheritance, this is never desirable.

* To make hidden names visible again, employ using declarations or forwarding functions.