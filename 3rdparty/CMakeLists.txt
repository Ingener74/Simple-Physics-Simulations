cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

ExternalProject_Add(
    external_OpenCV
    GIT_REPOSITORY git://github.com/Itseez/opencv.git
    GIT_TAG        2.4.5
    CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX=${SPS_INSTALL_3RDPARTY_DIR}
)
