cmake_minimum_required(VERSION 2.8)

include_directories(
	${CMAKE_BINARY_DIR}/3RDPARTY/include
	)
link_directories(
	${CMAKE_BINARY_DIR}/3RDPARTY/lib
	${CMAKE_BINARY_DIR}/3RDPARTY/lib64
	)

add_subdirectory(tools)
add_subdirectory(physics)
add_subdirectory(libgltool)

