### Be aware of template metaprogramming
Template metaprogramming (TMP) is the process of writing template-based C++ programs that execute during compilation. TMP was discovered, not invented. TMP has two great strengths. First, it makes some things easy that would otherwise be hard or impossible. Second, because template metaprograms execute during C++ compilation, they can shift work from runtime to compile-time. TMP has been shown to be Turing-complete, which means that it is powerful enough to compute anything. To grasp why TMP is worth knowing about, it's important to have a better understanding of what it can accomplish.
* Ensuring dimensional unit correctness
* Optimizing matrix operations
* Generating custom design pattern implementations
#### THINGS TO REMEMBER
* Template metaprogramming can shift work from runtime to compile-time, thus enabling earlier error detection and higher runtime performance.

* TMP can be used to generate custom code based on combinations of policy choices, and it can also be used to avoid generating code inappropriate for particular types.