add_library(
	visual-profiler
	include/visual_profiler.h
	src/visual_profiler.cpp
)

target_include_directories(visual-profiler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")