#include <iostream>

class Timer //timer base class
{
public:
    explicit Timer() {};
    virtual void timer() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class WidgetA : public Timer //widgetA is a Timer ? any client of widgetA can override timer
{
public:
    void test() { timer(); }
};

class WidgetB : private Timer //private inheritance. timer() is no longer accessible by widgetB clients
{
public:
    void test() { timer(); }
};

class WidgetC : private Timer //private inheritance. timer() is no longer accessible by widgetC clients but widgetC can override 
{
public:
    void test() { timer(); }

private:
    virtual void timer() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};


class WidgetD //better approach to replace private inheritance with composition and public inheritance
{
public:
    void test() { t.timer(); }

private:
    class DerivedTimer : public Timer
    {
        public:
        virtual void timer() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    };
    DerivedTimer t;
};

int main()
{
    WidgetA wA;
    wA.timer();
    wA.test();
    std::cout << "------------------------" << std::endl;
    WidgetB wB;
    // wB.timer();
    wB.test();
    std::cout << "------------------------" << std::endl;
    WidgetC wC;
    // wC.timer();
    wC.test();
    std::cout << "------------------------" << std::endl;
    WidgetD wD;
    // wD.timer();
    wD.test();
    std::cout << "------------------------" << std::endl;
    return 0;
}