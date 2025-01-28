#include <iostream>

class Top
{
};
class Middle : public Top
{
};
class Bottom : public Middle
{
};

template <typename T>
class SmartPtr
{
public:
    explicit SmartPtr(T *realPtr) : realPtr(realPtr)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    template <typename U>
    SmartPtr(const SmartPtr<U> &other)
        : realPtr(other.getPtr())
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

    T *getPtr() const { return realPtr; }

    SmartPtr(const SmartPtr &other)
        : realPtr(other.getPtr())
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

private:
    T *realPtr;
};