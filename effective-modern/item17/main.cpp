#include <memory>
#include <string>
#include <iostream>

class Widget
{
public:
    Widget() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    //copy
    Widget(const Widget &other) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Widget &operator=(const Widget &other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }

    //move
    Widget(Widget &&other) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    Widget &operator=(Widget &&other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }

    virtual ~Widget() = default;

private:
    int data1;
    std::string data2;
};

int main()
{
    Widget widget1;

    Widget widget2 (widget1);
    Widget widget3(std::move(widget1));

    widget2 = widget1;
    widget3 = std::move(widget1);
    return 0;
}