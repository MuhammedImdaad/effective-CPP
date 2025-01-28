#include "item43.h"

int main()
{
    LoggingMsgSender<CompanyA> msgSender;
    std::string msg = "Company A : hello world";
    msgSender.sendClearLog(msg);

    LoggingMsgSender<CompanyZ> msgSender1;
    std::string msg1 = "Company Z : hello world";
    // msgSender1.sendClearLog(msg1);
    return 0;
}