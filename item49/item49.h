#include <iostream>

class NewHandlerHolder
{
public:
    explicit NewHandlerHolder(std::new_handler handler)
        : oldHandler(handler){}

    ~NewHandlerHolder()
    {
        if (oldHandler) //if valid global NH existed, set it again
            std::set_new_handler(oldHandler);
    }

private:
    std::new_handler oldHandler;
    NewHandlerHolder(const NewHandlerHolder &); //cannot be copied
    NewHandlerHolder &operator=(const NewHandlerHolder &);
};

/////////////////////////////////////////////////////////
template <typename T>
class NewHandlerSupport
{
public:
    static void set_new_handler(std::new_handler p){currentHandler = p;};

    static void *operator new(std::size_t size)
    {
        NewHandlerHolder h(currentHandler); //restore the previous NH after performing new
        if (currentHandler != nullptr) 
            std::set_new_handler(currentHandler);

        new int[100000000000000000ul]; //to mimic bad_alloc
        return ::operator new(size);
    };

private:
    static std::new_handler currentHandler;
};

template <typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = nullptr;
//////////////////////////////////////////////////////////////////

class X : public NewHandlerSupport<X>
{
public:
    static void outOfMem()
    {
        std::cerr << __PRETTY_FUNCTION__ << " Memory allocation failed, terminating\n";
        std::abort();
    }

    X(){// allocation phase has already succeeded, meaning memory has been allocated.
    }
};

class Y : public NewHandlerSupport<Y>
{
public:
    static void outOfMem()
    {
        std::cerr << __PRETTY_FUNCTION__ << " Memory allocation failed, terminating\n";
        std::abort();
    }
};