### Understand the two meanings of typename
from C++'s point of view, class and typename mean exactly the same thing when declaring a template parameter. If a parser encounters a nested dependent name (names in a template that are dependent on a template parameter) in a template, it assumes that the name is not a type unless you tell it otherwise. By default, nested dependent names are not types. nested dependent type names are nested dependent names that refers to a `type` (not a data member). Check example.

The exception to the “typename must precede nested dependent type names” rule is that typename must not precede nested dependent type names in a list of base classes or as a base class identifier in a member initialization list. Example doesn't showcase this exception. 
#### THINGS TO REMEMBER
* When declaring template parameters, class and typename are interchangeable.

* Use typename to identify nested dependent type names, except in base class lists or as a base class identifier in a member initialization list.