cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME gltools)
project(${PROJECT_NAME})

find_package(OpenGL REQUIRED)
find_package(GLUT   REQUIRED)

include_directories(
    include
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
    )
	
link_directories(
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    )

file(GLOB gltools_src src/*.cpp)
file(GLOB gltools_hdr include/*.h)
	
add_library(${PROJECT_NAME} STATIC ${gltools_src} ${gltools_hdr})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${GLUT_glut_LIBRARY} GLEW)
