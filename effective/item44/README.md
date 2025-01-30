### Factor parameter-independent code out of templates
sometimes. If you're not careful, using templates can lead to code bloat: binaries with replicated (or almost replicated) code, data, or both. When you're writing a function and you realize that some part of the function's implementation is essentially the same as another function's implementation, You factor the common code out of the two functions, put it into a third function, and have both of the other functions call the new one. When writing templates, you do the same analysis, and you avoid replication in the same ways, but there's a twist. In template code, replication is implicit: there's only one copy of the template source code, so you have to train yourself to sense the replication that may take place when a template is instantiated multiple times.

Ex: template<typename T, std::size_t n> - This template takes a type parameter, T, but it also takes a parameter of type size_t — a non-type parameter. This is a classic way for template-induced code bloat to arise. This Item has discussed only bloat due to non-type template parameters, but type parameters can lead to bloat, too (int, long).
### Things to Remember
* Templates generate multiple classes and multiple functions, so any template code not dependent on a template parameter causes bloat.

* Bloat due to non-type template parameters can often be eliminated by replacing template parameters with function parameters or class data members.

* Bloat due to type parameters can be reduced by sharing implementations for instantiation types with identical binary representations.
