#include <cstring>

using namespace std;


class String
{
public:
    String(const char* s)
    {
        int length = strlen(s) + 1;
        text = new char[length];
        strcpy(text, s);        // text = s
    }
    // copy CTOR
    String(const String& original)
    {
        int length = strlen(original.text) + 1;
        text = new char[length];
        strcpy(text, original.text);        // text = s
    }
    // assignment
    String& operator=(const String& rhs)
    {
        if (this == &rhs) return *this;  // self copy check
        delete[] text;
        int length = strlen(rhs.text) + 1;
        text = new char[length];
        strcpy(text, rhs.text);        // text = s
        return *this;
    }

    ~String()
    {
        delete[] text;        
    }
private:
    char* text;
};

void f(String s)  // s is passed by copy (value)
{

}

String g()
{
    String red("red");
    return red;
}

int main()
{
    String blue("Blue");
    blue = g();    // blue.operator=(g())
    f(blue);
}