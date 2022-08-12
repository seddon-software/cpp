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
#    message(result)

    FILE(GLOB children ${curdir})
    SET(dirlist "")
    MESSAGE("")
  
    foreach(child ${children})
        # MESSAGE("child=${child}")
        LIST(APPEND dirlist ${child})
    ENDFOREACH()

    SET(${result} ${dirlist} PARENT_SCOPE)
ENDFUNCTION(findSubDirectories)

# fundamentals chapters
findSubDirectories(d1 "../[01][234]*")
# MESSAGE("d1 = **** ${d1}")

# advanced chapters
findSubDirectories(d2 "../A[01][234]*")

# print results
foreach(d ${d1})
    message(">> ${d}")
#   add_subdirectory(../A01_Lambdas ../A01_Lambdas)
    include("${d}/CMakeLists.txt")
endforeach()

#MESSAGE("d2 = **** ${d2}")

# function(setVariable varName value)
    # set(${varName} ${value})
    # set(${varName} ${${varName}} PARENT_SCOPE)
    # message("setVariable: ${varName} = ${${varName}}")
# endfunction()

# setVariable(Foobar "Assign this value to Foobar")
# message("Foobar = ${Foobar}")

