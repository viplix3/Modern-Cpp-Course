add_executable(
	main
	src/main.cpp
)


target_include_directories(main PRIVATE ../visual_profiler/)
target_link_libraries(main PRIVATE textual-profiler)