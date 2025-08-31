## Prefer alias declarations to typedefs
typedefs are soooo C++98. They work in C++11, sure, but C++11 also offers alias declarations. Given that the typedef and the alias declaration do exactly the same thing, it’s reasonable to wonder whether there is a solid technical reason for preferring one over the other.    
1. Alias declaration easier to swallow when dealing with types involving function pointers.    
2. Alias declarations can be templatized.  
3. Standardization Committee adapted alias for templates in C++14 for all the C++11 type transformation. 
### THINGS TO REMEMBER
* typedefs don’t support templatization, but alias declarations do.

* Alias templates avoid the “::type” suffix and, in templates, the “typename” prefix often required to refer to typedefs.

* C++14 offers alias templates for all the C++11 type traits transformations.