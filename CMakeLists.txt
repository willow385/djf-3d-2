cmake_minimum_required(VERSION 3.13)
project(djf-3d-2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SDL2_PATH "" CACHE PATH "Where (if) SDL2 is installed locally.")
list(APPEND CMAKE_PREFIX_PATH "${SDL2_PATH}/lib/cmake")
find_package(SDL2 REQUIRED CONFIG)

include(GNUInstallDirs)
add_subdirectory(src)


install(DIRECTORY "${SDL2_PATH}/"
    DESTINATION "${CMAKE_INSTALL_BINDIR}/SDL2")
set(SDL2CMakePrefixPath "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/SDL2/lib/cmake")
configure_file(djf-3d-2Config.cmake.in djf-3d-2Config.cmake @ONLY)

# Source :https://cliutils.gitlab.io/modern-cmake/chapters/install/installing.html

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/djf-3d-2Config.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/djf-3d-2")
