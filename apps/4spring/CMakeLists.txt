cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME 4spring)
project(${PROJECT_NAME})

find_package(OpenGL REQUIRED)
find_package(GLUT   REQUIRED)

include_directories(
    ../../modules/physics/include
    ../../modules/libgltool/include
    ${SPS_INSTALL_3RDPARTY_DIR}/include
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIR}
    )
link_directories(
    ${SPS_INSTALL_3RDPARTY_DIR}/lib
    ${SPS_INSTALL_3RDPARTY_DIR}/lib64
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    )
    
    
set(SOURCES src/main.cpp)

set(OPENCV_LIBS opencv_core opencv_highgui opencv_imgproc)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OPENCV_LIBS} ${OPENGL_gl_LIBRARY} ${GLUT_glut_LIBRARY} GLEW physics gltools)
