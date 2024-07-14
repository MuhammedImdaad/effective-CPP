### Prefer non-member non-friend functions to member functions
The non-member approach is thus better than a member function in many ways. It's important to understand why. If something is encapsulated, it's hidden from view. The greater something is encapsulated, then, the greater our ability to change it. That's the reason we value encapsulation in the first place: it affords us the flexibility to change things in a way that affects only a limited number of clients. The choice yielding greater encapsulation is the non-member non-friend function, because it doesn't increase the number of functions that can access the private parts of the class. Worth noting, this reasoning applies only to non-member non-friend functions. 

So, we could make such functions a static member function of some utility class. In C++, a more natural approach would be to make such functions a non-member function in the same namespace as the primary object. Importantly, namespaces, unlike classes, can be spread across multiple source files.

#### THINGS TO REMEMBER
*  Prefer non-member non-friend functions to member functions. Doing so increases encapsulation, packaging flexibility, and functional extensibility.
