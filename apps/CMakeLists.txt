cmake_minimum_required(VERSION 2.8)

include_directories(
	${CMAKE_BINARY_DIR}/3RDPARTY/include
	)
link_directories(
	${CMAKE_BINARY_DIR}/3RDPARTY/lib
	)

add_subdirectory(simple_cloth)

add_subdirectory(rocket_start)
#add_dependencies(rocket_start external_OpenCV)

add_subdirectory(4spring)

