#include "item.h"

int main()
{
    auto ptr = createWidget();
    std::cout << ptr.use_count() << std::endl; // 1
    auto ptr1 = ptr;
    std::cout << ptr.use_count() << " " << ptr1.use_count() << std::endl; // 2
    auto ptr2 = std::move(ptr);
    std::cout << ptr.use_count() << " " << ptr2.use_count() << std::endl; // still 2 not 3, ptr is moved(no longer valid)
    std::cout << ptr << " " << ptr1 << " " << ptr2 << " " << &ptr2 << std::endl; // ptr is null, ptr1 == ptr2 == new Widget

    std::unique_ptr<Widget> ptrU(new Widget);
    std::shared_ptr<Widget> ptr4 = std::move(ptrU);
    // std::unique_ptr<Widget> ptr5 = std::move(ptr4); //error: conversion from ‘aka ‘std::shared_ptr<Widget>’ to non-scalar type ‘std::unique_ptr<Widget>’ requested
    return 0;
}