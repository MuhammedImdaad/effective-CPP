#include <iostream>

using namespace std;

class File
{
public:
    File(int x) { cout << __PRETTY_FUNCTION__ << endl; }
    File() { cout << __PRETTY_FUNCTION__ << endl; }
};

class InputFile : virtual public File
{
public:
    InputFile(int x) : File(x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class OutputFile : virtual public File
{
public:
    OutputFile(int x) : File(x)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class IOFile : public InputFile, public OutputFile
{
public:
    IOFile(int x = 0) : InputFile(x), OutputFile(x)
    { // add File(x) if you want to explicitly call the parameterized constructor
        cout << __PRETTY_FUNCTION__ << endl;
    }
};