#include <iostream>

void authenticateUser();

template <typename Container, typename Index>
decltype(auto) authAndAccess(Container &&c, Index i)
{
    authenticateUser();
    return std::forward<Container>(c)[i];
}

/* authAndAccess authenticates and returns c[i]. through universal reference, 
it supports both lvalue and rvalue references parameters. 
depending on container c, std::forward<T> returns an lvalue or rvalue object.

without this apporach, me may need to obtain a copy of the container to support rvalue. 
operator c[i] who is returning an lvalue reference for an rvalue object will be destroyed while returning. 

forwarding in C++ that helps retain the value category (lvalue or rvalue) of function parameters 
when passing them to another function while preventing unnecessary copies when passing objects and 
reserves rvalue references.

auto specified that we need to deduce the return type. decltype make sure return type is equal to c[i].
otherwise as case 3 in item 1, auto will deduce T& -> T. 
*/