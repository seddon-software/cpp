// see: https://blog.feabhas.com/2021/08/c20-modules-with-gcc11/

/*
valid gcc extensions +> preprocess & compile
    file.cc
    file.cp
    file.cxx
    file.cpp
    file.c++
    file.C
*/

module;         // introduces the global fragment

// global fragment (only preprocessor directives)
// e.g. #define BUFFER 512

// module preamble (only import declarations - don't forget the semi-colon)
import <iostream>;  

// module purview (export declarations)
export module helloWorld;  // name our module and export

// module local section (except exported items)
export void helloWorld() { // only exported functions have global scope
    std::cout << "hello, world!\n";
}

