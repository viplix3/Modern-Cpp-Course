cmake_minimum_required(VERSION 3.16)

# set the project name
set(${PROJECT} hw-2-task-2)
project("${PROJECT}")

add_library(ipb_airthmetic src/sum.cpp src/subtract.cpp)

# the executable for running the project
add_executable(main src/main.cpp)

# linking executable with libarary
target_link_libraries(main PUBLIC ipb_airthmetic)

# add libary includes to the search path
target_include_directories(ipb_airthmetic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")