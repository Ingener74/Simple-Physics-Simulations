cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME tools)
project(${PROJECT_NAME})

include_directories(include)

file(GLOB TOOLS_SRC src/*.cpp)
file(GLOB TOOLS_HDR include/*.h)

add_library(${PROJECT_NAME} STATIC ${TOOLS_SRC})
