cmake_minimum_required(VERSION 3.16)
project(djf-3d-2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/external/SDL2-2.0.10/SDL2/lib/cmake")
find_package(SDL2 REQUIRED CONFIG)

add_subdirectory(src)
add_library(djf-3d-2 INTERFACE)
target_include_directories(djf-3d-2 INTERFACE
    $<BUILD_INTERFACE:"${CMAKE_CURRENT_LIST_DIR}/include">
    $<INSTALL_INTERFACE:include>)
target_link_libraries(djf-3d-2 INTERFACE
    Vec2f
    Vec3f
    Perspective
    Model3d
    Scene
    Canvas
    KeyboardStateAndColorAndPolygon
)

# add_executable(Demo demo/main.cpp)
# target_link_libraries(Demo PRIVATE djf-3d-2)
# target_include_directories(Demo PRIVATE 
#     $<BUILD_INTERFACE:"${CMAKE_CURRENT_LIST_DIR}/include">
#     $<INSTALL_INTERFACE:include>)

# add_custom_target(createDemo ALL
#     COMMAND Demo "${CMAKE_CURRENT_LIST_DIR}/demo/utah_teapot.obj")

include(GNUInstallDirs)
install(TARGETS djf-3d-2 Vec2f Vec3f Perspective Model3d Scene Canvas KeyboardStateAndColorAndPolygon
    EXPORT djf-3d-2-export
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

install(EXPORT djf-3d-2-export
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/djf-3d-2
    NAMESPACE djf-3d-2::
    FILE djf-3d-2Config.cmake
  )
