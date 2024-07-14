### Declare data members private
If data members aren't public, the only way for clients to access an object is via member functions. Functions gives you much more precise control over the accessibility of data members. Hiding data members behind functional interfaces can offer all kinds of implementation flexibility. If you hide your data members from your clients (i.e., encapsulate them), you can ensure that class invariants are always maintained, because only member functions can affect them. Protected data members are as unencapsulated as public ones, because in both cases, if the data members are changed, an unknowably large amount of dependent code is broken. From an encapsulation point of view, there are really only two access levels: private (which offers encapsulation) and everything else (which doesn't).
#### THINGS TO REMEMBER
* Declare data members private. It gives clients syntactically uniform access to data, affords fine-grained access control, allows invariants to be enforced, and offers class authors implementation flexibility.

* protected is no more encapsulated than public.
