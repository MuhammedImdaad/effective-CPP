 ### Make sure that objects are initialized before they're used

For most types, a single call to a copy constructor is more efficient — sometimes much more efficient — than a call to the default constructor followed by a call to the copy assignment operator. Therefore make use of initilization list.
Constant (const) and reference (&) members must be initialized using an initialization list. They cannot be assigned values inside the constructor body because they must be initialized at the time of their creation.