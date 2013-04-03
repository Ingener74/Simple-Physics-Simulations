cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME cloth_test)
project(${PROJECT_NAME})

IF(${ANDROID})
ELSE(${ANDROID})
ENDIF(${ANDROID})

file(GLOB SOURCES src/*.cpp)

SET(ALL_LIBS )

IF(${ANDROID})
    SET(ALL_LIBS ${ALL_LIBS} android log GLESv2)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
ELSE(${ANDROID})
    SET(ALL_LIBS ${ALL_LIBS} GL GLU GLEW)
    add_executable(${PROJECT_NAME} ${SOURCES})
ENDIF(${ANDROID})

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})