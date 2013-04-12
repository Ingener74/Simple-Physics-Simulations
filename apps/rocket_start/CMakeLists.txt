cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME rocket_start)
project(${PROJECT_NAME})

find_package(OpenCV REQUIRED)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} opencv_core opencv_highgui opencv_imgproc)
