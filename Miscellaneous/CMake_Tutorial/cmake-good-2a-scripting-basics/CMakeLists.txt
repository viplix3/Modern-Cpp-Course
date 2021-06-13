# Specify the minimum cmake version required for the project
cmake_minimum_required(VERSION 3.16)

# This will set PROJECT_NAME variable to CMAKE-TUTORAL
set(PROJECT_NAME CMAKE-TUTORIAL)

# Setting the project name, this should be done in the root CMakeLists.txt or else CMake behaves weird
# The weird syntax ${} is used to dereference a variable. It is recommended to always used quotes "" when dereferencing a variable
# as the variable might contain spaces which can cause issues when dereferencing the variable. Wrapping variable deferencing in quotes
# Makes the procedure safer
project("${PROJECT_NAME}" VERSION 1.0.3)

# Everything in CMake is a string, and all the arguments to CMake functions are space separated
# Hence, in a case we need to use a string having spaces, it should be wrapped in quotes ""
# messae() prints a message when running cmake
message(STATUS "This is a random message")