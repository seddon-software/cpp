namespace abc
{
    void f()
    {

    }
}
namespace abc
{
    void g()
    {

    }
}

namespace xyz
{
    void f()
    {

    }
    void h()
    {

    }
}

void w()
{

}
int x = 100;
using namespace abc;
using namespace xyz;

int main()
{
    int x = 200;
    int y = ::x;
    ::w();
    h();
    abc::g();
}
