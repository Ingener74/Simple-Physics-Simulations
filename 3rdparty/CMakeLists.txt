cmake_minimum_required(VERSION 2.8)

include(ExternalProject)

ExternalProject_Add(
    external_OpenCV

    GIT_REPOSITORY git://github.com/Itseez/opencv.git
)
