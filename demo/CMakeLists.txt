cmake_minimum_required(VERSION 3.13)
project(demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(djf-3d-2 REQUIRED CONFIG)
add_executable(Demo main.cpp)
target_link_libraries(Demo PRIVATE djf-3d-2::djf-3d-2)

# this will fail in Docker since the current image doesn't support making a window.
add_custom_target(createDemo ALL
    COMMAND Demo "${CMAKE_CURRENT_LIST_DIR}/utah_teapot.obj")