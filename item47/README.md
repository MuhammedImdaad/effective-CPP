### Use traits classes for information about types
There are five categories of iterators, corresponding to the operations they support.
* Input iterators
* Output iterators
* Forward iterators
* Bidirectional iterators 
* Random access iterators

If we need to get some information about a type, that's what traits let you do: they allow you to get information about a type during compilation. The traits information for a type, is external to the type. The standard technique is to put it into a template and one or more specializations of that template. For iterators, the template in the standard library is named `iterator_traits`.
iterator_traits implements for user-defined objects, First, it imposes the requirement that any user-defined iterator type must contain a nested typedef named iterator_category that identifies the appropriate tag struct and iterator_traits just parrots back the iterator class's nested typedef.
```
template<typename IterT>
struct iterator_traits {
  typedef typename IterT::iterator_category iterator_category;
};
```
The second part of the iterator_traits implementation handles iterators that are pointers by offering a partial template specialization for pointer types. Pointers act as random access iterators, so that's the category iterator_traits specifies for them:

```
template<typename IterT>
struct iterator_traits<IterT*>

{
  typedef random_access_iterator_tag iterator_category;

};
```
Therefore, IterT's type is `known during compilation.` Example contain compile and run time template specialization. 
#### THINGS TO REMEMBER
* Traits classes make information about types available during compilation. They're implemented using templates and template specializations.

* In conjunction with overloading, traits classes make it possible to perform compile-time if...else tests on types.