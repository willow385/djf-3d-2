cmake_minimum_required(VERSION 3.13)
project(djf-3d-2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)

add_subdirectory(src)

# Source :https://cliutils.gitlab.io/modern-cmake/chapters/install/installing.html

install(FILES "${CMAKE_CURRENT_LIST_DIR}/djf-3d-2Config.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/djf-3d-2")