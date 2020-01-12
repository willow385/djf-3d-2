include(CMakeFindDependencyMacro)

find_dependency(SDL2 REQUIRED CONFIG)

include("${CMAKE_CURRENT_LIST_DIR}/djf-3d-2Targets.cmake")
