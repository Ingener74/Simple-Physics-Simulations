cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME cloth_test)
project(${PROJECT_NAME})

include_directories(../../modules/tools/include)

IF(${ANDROID})
ELSE(${ANDROID})
ENDIF(${ANDROID})

file(GLOB SOURCES src/*.cpp)

SET(ALL_LIBS tools)

IF(${ANDROID})
    SET(ALL_LIBS ${ALL_LIBS} android log GLESv2)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
ELSE(${ANDROID})
    SET(ALL_LIBS ${ALL_LIBS})
    add_executable(${PROJECT_NAME} ${SOURCES})
ENDIF(${ANDROID})

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})