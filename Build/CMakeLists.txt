#########################################
#  Invoke this cmake with:
#
# cmake -S .
# cmake --build .
#########################################

cmake_minimum_required(VERSION 3.10)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -g)
set(CMAKE_RULE_MESSAGES:BOOL=OFF)
project("Build All")
# add_subdirectory(../A01_Lambdas ../A01_Lambdas)
# add_subdirectory(../A03_NewFeatures ../A03_NewFeatures)
# include(../A01_Lambdas/CMakeLists.txt)
# include(../A03_NewFeatures/CMakeLists.txt)

function(findSubDirectories result curdir)
    FILE(GLOB children ${curdir})
    SET(dirlist "")
    MESSAGE("")
  
    foreach(child ${children})
        MESSAGE("child=${child}")
        LIST(APPEND dirlist ${child})
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDFUNCTION()

# fundamentals chapters
findSubDirectories(d1 "../[0-9][0-9]*")

# advanced chapters
findSubDirectories(d2 "../A[0-9][0-9]*")

# print results
MESSAGE("**** ${d1}")
MESSAGE("**** ${d2}")

