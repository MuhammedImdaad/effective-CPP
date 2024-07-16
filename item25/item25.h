#include <iostream>
#include <vector>

namespace custom
{
    class WidgetImpl
    {
    public:
    private:
        int a, b, c;
        std::vector<double> v;
    };

    class Widget
    {
    public:
        Widget()
        {
            pImpl = new WidgetImpl();
        }
        ~Widget() { delete pImpl; }

        Widget(const Widget &rhs)
        {
            pImpl = new WidgetImpl(*(rhs.pImpl));
        };

        Widget &operator=(const Widget &rhs)
        {
            *pImpl = *(rhs.pImpl);
            return *this;
        }

        void swap(Widget &other)
        {
            std::cout << "calling member swap\n";
            using std::swap;
            swap(pImpl, other.pImpl);
        }

    private:
        WidgetImpl *pImpl;
    };

    void swap(Widget &a,
                      Widget &b)
                      {
                        std::cout << "calling non member swap\n";
                        a.swap(b);
                      }
}

namespace std
{
    template <>
    void swap<custom::Widget>(custom::Widget &a,
                      custom::Widget &b)
    {
        std::cout << "calling std swap\n";
        a.swap(b);
    }
};