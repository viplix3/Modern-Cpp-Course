cmake_minimum_required(VERSION 3.16)

set("${PROJECT_NAME}" CPP_PROFILER)
project("${PROJECT_NAME}" VERSION 1.0.0)

add_subdirectory(textual_profiler)
add_subdirectory(main)