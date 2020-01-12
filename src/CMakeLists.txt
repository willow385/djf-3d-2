cmake_minimum_required(VERSION 3.13)

add_library(Vec2f Vec2f.cpp Vec2f.h)
target_compile_options(Vec2f PRIVATE -O3 -Wall -fPIC)

add_library(Perspective Perspective.cpp Perspective.h)
target_link_libraries(Perspective PRIVATE Vec2f)
target_compile_options(Perspective PRIVATE -O3 -Wall -fPIC)

add_library(Vec3f Vec3f.cpp Vec3f.h)
target_link_libraries(Vec3f PRIVATE Vec2f Perspective)
target_compile_options(Vec3f PRIVATE -O3 -Wall -fPIC)

add_library(Model3d Model3d.cpp Model3d.h)
target_link_libraries(Model3d PRIVATE Vec3f)
target_compile_options(Model3d PRIVATE -O3 -Wall -fPIC)

add_library(Scene Scene.cpp Scene.h)
target_link_libraries(Scene PRIVATE Vec2f Vec3f Model3d)
target_compile_options(Scene PRIVATE -O3 -Wall -fPIC)

# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/external/SDL2-2.0.10/SDL2/lib/cmake")
find_package(SDL2 REQUIRED CONFIG)
add_library(Canvas Canvas.cpp Canvas.h)
target_link_libraries(Canvas PRIVATE SDL2::SDL2 Vec2f Perspective Vec3f Model3d Scene)
target_compile_options(Canvas PRIVATE -O3 -Wall -fPIC)

add_library(KeyboardStateAndColorAndPolygon INTERFACE)
target_include_directories(KeyboardStateAndColorAndPolygon INTERFACE 
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

add_library(djf-3d-2 INTERFACE)
target_include_directories(djf-3d-2 INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_libraries(djf-3d-2 INTERFACE
    Vec2f
    Vec3f
    Perspective
    Model3d
    Scene
    Canvas
    KeyboardStateAndColorAndPolygon
)

include(GNUInstallDirs)

install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/djf-3d-2"
    FILES_MATCHING
    PATTERN *.h 
    PATTERN *.hpp)

install(TARGETS 
    djf-3d-2
    Vec2f
    Vec3f 
    Perspective 
    Model3d 
    Scene 
    Canvas
    KeyboardStateAndColorAndPolygon
    EXPORT djf-3d-2Targets
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}/djf-3d-2"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/djf-3d-2"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}/djf-3d-2"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/djf-3d-2"
)

install(EXPORT djf-3d-2Targets
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/djf-3d-2"
    NAMESPACE djf-3d-2::
    FILE djf-3d-2Targets.cmake
)

