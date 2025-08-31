#include "item.h"

int main()
{
    Widget w1;
    const Widget w2;

    Widget w3{std::move(w1)}; // calls move
    Widget w4{std::move(w2)}; // calls copy

    Widget w;

    // processLvalue(Widget{}); // error: cannot bind non-const lvalue reference of type ‘Widget&’ to an rvalue of type ‘Widget’

    // processRvalue(w); // error: cannot bind rvalue reference of type ‘Widget&&’ to lvalue of type ‘Widget’

    logAndProcess(w);            // lvalue - void process(const Widget&)
    logAndProcess(std::move(w)); // rvalue - void process(Widget&&)
    logAndProcess(Widget{});     // rvalue - void process(Widget&&)

    /*
        Widget::Widget()
        Widget::Widget()
        Widget::Widget(Widget&&)
        Widget::Widget(const Widget&)
        Widget::Widget()
        void logAndProcess(T&&) [with T = Widget&]
        void process(const Widget&)
        void logAndProcess(T&&) [with T = Widget]
        void process(Widget&&)
        Widget::Widget()
        void logAndProcess(T&&) [with T = Widget]
        void process(Widget&&)
        Widget::~Widget()
        Widget::~Widget()
        Widget::~Widget()
        Widget::~Widget()
        Widget::~Widget()
        Widget::~Widget()
    */
    return 0;
}