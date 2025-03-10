### Consider alternatives to virtual functions
The fundamental advice of this Item is to consider alternatives to virtual functions when searching for a design for the problem you're trying to solve. Here's a quick recap the alternatives.

* Use the non-virtual interface idiom (NVI idiom), a form of the Template Method design pattern that wraps public non-virtual member functions around less accessible virtual functions.

* Replace virtual functions with function pointer data members, a stripped-down manifestation of the Strategy design pattern.

* Replace virtual functions with tr1::function data members, thus allowing use of any callable entity with a signature compatible with what you need. This, too, is a form of the Strategy design pattern.

* Replace virtual functions in one hierarchy with virtual functions in another hierarchy. This is the conventional implementation of the Strategy design pattern.

This isn't an exhaustive list of design alternatives to virtual functions, but it should be enough to convince you that there are alternatives. Furthermore, their comparative advantages and disadvantages should make clear that you should consider them.

To avoid getting stuck in the ruts of the road of object-oriented design, give the wheel a good jerk from time to time. There are lots of other roads. It's worth taking the time to investigate them.

### Things to Remember
* Alternatives to virtual functions include the NVI idiom and various forms of the Strategy design pattern. The NVI idiom is itself an example of the Template Method design pattern.

* A disadvantage of moving functionality from a member function to a function outside the class is that the non-member function lacks access to the class's non-public members.

* tr1::function objects act like generalized function pointers. Such objects support all callable entities compatible with a given target signature.
