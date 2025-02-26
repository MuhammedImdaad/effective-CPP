## Prefer lambdas to std::bind
In C++11, lambdas are almost always a better choice than std::bind. As of C++14, the case for lambdas isn’t just stronger, it’s downright ironclad.     
The most important reason to prefer lambdas over std::bind is that lambdas are more readable. Another reason is lambda function invocation can be inlined by compilers. It’s thus possible that using lambdas generates faster code than using std::bind.   
Compared to lambdas, code using std::bind is less readable, less expressive, and possibly less efficient.       
`In C++14, there are no reasonable use cases for std::bind. `

### THINGS TO REMEMBER
* Lambdas are more readable, more expressive, and may be more efficient than using std::bind.
* In C++11 only, std::bind may be useful for implementing move capture or for binding objects with templatized function call operators.