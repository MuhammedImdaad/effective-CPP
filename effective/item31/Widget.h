#pragma once

#include <memory>  // For std::unique_ptr
class WidgetImpl;  // Forward declaration of implementation class
// #include <WidgetImpl.h>

class Widget {
public:
    Widget();
    ~Widget();
    void doSomething();

private:
    WidgetImpl* pImpl ;  // Pointer to implementation
};
