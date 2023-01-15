cmake_minimum_required(VERSION 3.22)
project(unique_names)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra")

add_subdirectory(names_holder_lib)
add_subdirectory(tests)
add_subdirectory(app)