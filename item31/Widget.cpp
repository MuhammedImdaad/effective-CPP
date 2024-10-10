#include "Widget.h"
#include "WidgetImpl.h"  // Include implementation details

Widget::Widget() : pImpl(new WidgetImpl) {}
Widget::~Widget(){delete pImpl;};

void Widget::doSomething() {
    pImpl->doSomething();
}
