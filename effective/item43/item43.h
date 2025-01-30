#include <iostream>

class CompanyA
{
public:
    void sendClear(const std::string &msg)
    {
        std::cout << "clear : " << msg << std::endl;
    }

    void sendEncrypt(const std::string &msg)
    {
        std::cout << "encrypt : " << msg << std::endl;
    }
};

class CompanyZ
{
public:
    void sendEncrypt(const std::string &msg)
    {
        std::cout << "encrypt : " << msg << std::endl;
    }
};

template <typename Company>
class MsgSender
{
public:
    void sendClear(const std::string &msg)
    {
        Company c;
        c.sendClear(msg);
    }

    void sendEncrypt(const std::string &msg)
    {
        Company c;
        c.sendEncrypt(msg);
    }
};

/* it's a specialized version of the MsgSender template to be used when the template argument is CompanyZ. 
This is known as a total template specialization: the template MsgSender is specialized for the type CompanyZ*/
template <>
class MsgSender<CompanyZ>
{
public:
    void sendEncrypt(const std::string &msg)
    {
        CompanyZ c;
        c.sendEncrypt(msg);
    }
};

template <typename Company>
class LoggingMsgSender : public MsgSender<Company>
{
    // option 2
    //  using MsgSender<Company>::sendClear;
public:
    void sendClearLog(const std::string &msg)
    {
        std::cout << "logging metadata\n";

        // won't compile
        // sendClear(msg);

        // option 1
         this->sendClear(msg);

        // option 3
        //  MsgSender<Company>::sendClear(msg);
    }
};