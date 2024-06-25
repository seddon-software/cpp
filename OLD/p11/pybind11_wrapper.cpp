// pybind11_wrapper.cpp
#include <pybind11/pybind11.h>
double multiply(double, double);

PYBIND11_MODULE(pybind11_example, m) {
    m.doc() = "pybind11 example plugin"; // Optional module docstring
    m.def("cpp_function", &multiply, "A function that multiplies two numbers");
}

