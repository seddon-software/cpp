cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

FILE(GLOB sources *.cpp)

foreach(source ${sources})
    get_filename_component(exeFile ${source}.exe NAME)
    string(REPLACE ".cpp" "" exe ${exeFile})
    ADD_EXECUTABLE(${exe} ${source})
endforeach()


