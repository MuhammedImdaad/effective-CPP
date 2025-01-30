#include <iostream>

class Custom
{
public:
    Custom(int age); //Define seperately to avoid inlining

    int getAge() const { return age; }
    int getAgeLow();

private:
    int age;
};

// inline int someAge();
int someAge();