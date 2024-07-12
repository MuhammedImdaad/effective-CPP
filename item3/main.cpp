#include "item3.h"
#include <vector>

void constPointers()
{
    char greet[] = "hello";
    char name[] = "Imdaad";

    const char* constP = greet;
    // constP[0] = 'J'; error, points to is a const
    constP = name;

    char* const pConst = greet;
    pConst[0] = 'J';
    // pConst = name; error, pointer is const

    std::vector<int> v;
    std::vector<int>::const_iterator itr = v.begin();

    // *itr = 10; cannot modify data
    itr++;
}

void printBook(Book& book)
{
    char first = book[0];
}

void printBook(const Book& book)
{
    char first = book[0];
}

int main()
{
    constPointers();

    Book b1("Text 1");
    const Book b2("Text 2");

    printBook(b1); // non const object may call either the const or non const method
    printBook(b2); // constant object calls constant method
}