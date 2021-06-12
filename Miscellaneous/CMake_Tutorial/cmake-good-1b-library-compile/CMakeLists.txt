cmake_minimum_required(VERSION 3.16)

project(Tutorial VERSION 1.0.1)

add_library(
	say-hello
	hello.hpp
	hello.cpp
)

add_executable(cmake-good main.cpp)

target_link_libraries(cmake-good PRIVATE say-hello)