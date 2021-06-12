add_executable(cmake-good-library src/main.cpp)

target_link_libraries(cmake-good-library PRIVATE say-hello)