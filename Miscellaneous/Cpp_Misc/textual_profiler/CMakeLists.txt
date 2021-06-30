add_library(
	textual-profiler
	include/textual_profiler.h
	src/textual_profiler.cpp
)

target_include_directories(textual-profiler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")