cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME rocket_start)
project(${PROJECT_NAME})

include_directories(
	../../modules/physics/include
	)

file(GLOB SOURCES src/*.cpp)

set(OPENCV_LIB opencv_core opencv_highgui opencv_imgproc)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OPENCV_LIB} physics)
