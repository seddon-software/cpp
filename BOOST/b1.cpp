#define BOOST_BIND_GLOBAL_PLACEHOLDERS

char const* greet()
{
   return "hello, world";
}

char const* greet2()
{
   return "hello, world 2";
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(b1_lib)  // shared object name (python name to import)
{
    using namespace boost::python;
    //  def(python_name, cpp_name)
    def("f1", greet);
    def("f2", greet2);
}

