add_library(
	say-hello
	src/hello.hpp
	src/hello.cpp
)

# CMAKE_CURRENT_SOURCE_DIR contains the directory of current CMakeLists.txt being processed
target_include_directories(say-hello PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")