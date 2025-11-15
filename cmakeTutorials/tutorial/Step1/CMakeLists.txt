cmake_minimum_required(VERSION 3.23)
project(Tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(Tutorial)

target_sources(Tutorial
    PRIVATE
    Tutorial/Tutorial.cxx
)

target_compile_options(Tutorial PRIVATE -save-temps )

# TODO1: Set the minimum required version of CMake to be 3.23

# TODO2: Create a project named Tutorial

# TODO3: Add an executable target called Tutorial to the project

# TODO4: Add the Tutorial/Tutorial.cxx source file to the Tutorial target

# TODO7: Add the MathFunctions library as a linked dependency
#        to the Tutorial target

# TODO11: Add the Tutorial subdirectory to the project

# TODO5: Add a library target called MathFunctions to the project

# TODO6: Add the source and header file located in Step1/MathFunctions to the
#        MathFunctions target, note that the intended way to include the
#        MathFunctions header is:
#          #include <MathFunctions.h>

# TODO13: Add the MathFunctions subdirectory to the project
