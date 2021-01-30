#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <string>
using namespace std;

auto average(double d1, double d2)
{
   return (d1 + d2)/2.0;
}

auto sum(double d1, double d2)
{
   return d1 + d2;
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(b3_lib)
{
    using namespace boost::python;
    def("average", average);
    def("sum", sum);
}

