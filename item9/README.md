 ### Never call virtual functions during construction or destruction

 During base class construction, virtual functions never go down into derived classes. Instead, the object behaves as if it were of the base type. Calling down to parts of an object that have not yet been initialized is inherently dangerous, so C++ gives you no way to do it.

#### THINGS TO REMEMBER
* Don't call virtual functions during construction or destruction, because such calls will never go to a more derived class than that of the currently executing constructor or destructor.