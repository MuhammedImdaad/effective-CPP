## Familiarize yourself with alternatives to overloading on universal references
overloading on universal references can lead to a variety of problems, yet there are also places where such overloading could be useful. If only it would behave the way we’d like! This Item explores ways to achieve the desired behavior, either through designs that avoid overloading on universal references or by employing them in ways that constrain the types of arguments they can match.
* Abandon overloading
* Pass by const T&
    * revert to C++98 and replace pass-by-universal-reference with pass-by-lvalue-reference-to-const. 
* Pass by value
* Use Tag dispatch
    * If the motivation for the use of a universal reference is perfect forwarding, we have to use a universal reference; there’s no other choice. So if we don’t give up overloading and we don’t give up universal references, how can we avoid overloading on universal references? Example. 
    * In this design, the types std::true_type and std::false_type are “tags” whose only purpose is to force overload resolution to go the way we want. 
    * What’s important about tag dispatch is less how it works and more how it permits us to combine universal references and overloading without the problems described in Item 26. 
* Constraining templates that take universal references
    * Most of the time you implement your copy and move constructors in the conventional fashion and you do not want the universal reference function to be invoked as constructors. we’d like to enable the Class perfect-forwarding constructor only if the type being passed isn’t the Class type. 
    * Std::enable_if (conditional check) gives you a way to force compilers to behave as if a particular template didn’t exist. Such templates are said to be disabled. The way to express that idea isn’t particularly difficult, but the syntax is off-putting, especially if you’ve never seen it before.
    *  To strip any references, consts, and volatiles from T before checking to see if that type is the same as Person, the form of a type trait is std::decay. std::decay<T>::type is the same as T, except that references and cv-qualifiers (const or volatile qualifiers) are removed.
    * Given the declaration, constructing an Object from another same object type lvalue or rvalue, const or non-const, volatile or non-volatile, a class derived from object — will never invoke the constructor taking a universal reference!

The first three techniques, specify a type for each parameter in the function(s) to be called. The last two techniques, don’t specify types for the parameters. The fundamental decision—to specify a type or not—has consequences.     
As a rule, perfect forwarding is more efficient, because it avoids the creation of temporary objects. But perfect forwarding has drawbacks. One is that some kinds of arguments can’t be perfect-forwarded. A second issue is the comprehensibility of error messages when clients pass invalid arguments. 
### THINGS TO REMEMBER
* Alternatives to the combination of universal references and overloading include the use of distinct function names, passing parameters by lvalue-reference-to-const, passing parameters by value, and using tag dispatch.
* Constraining templates via std::enable_if permits the use of universal references and overloading together, but it controls the conditions under which compilers may use the universal reference overloads.
* Universal reference parameters often have efficiency advantages, but they typically have usability disadvantages.