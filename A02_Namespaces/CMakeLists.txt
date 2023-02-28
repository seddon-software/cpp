cmake_minimum_required(VERSION 3.22)
include("../Build2/compileAll.cmake")
project(CMAKE)

add_subdirectory(NamespaceExamples NamespaceExamples/build)
add_subdirectory(NamespacesInLibraries NamespacesInLibraries/build) 

