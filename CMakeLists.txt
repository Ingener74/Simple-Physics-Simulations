cmake_minimum_required(VERSION 2.8)

# repository root dir
set(SPS_ROOT ${CMAKE_CURRENT_LIST_DIR})

# install dirs
set(SPS_INSTALL_DIR ${SPS_ROOT}/install)
set(SPS_INSTALL_3RDPARTY_DIR ${SPS_INSTALL_DIR}/3rdparty)

# set install prefix to 
set(CMAKE_INSTALL_PREFIX ${SPS_INSTALL_DIR})

add_subdirectory(3rdparty)
add_subdirectory(apps)
add_subdirectory(modules)
