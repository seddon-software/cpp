#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <string>
using namespace std;

string greet2()
{
   return "goodbye universe";
}

char const* greet()
{
   return "hello, world";
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(b2_lib)
{
    using namespace boost::python;
    def("f1", greet);
    def("f2", greet2);
}

