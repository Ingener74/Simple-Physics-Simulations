cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME physics)
project(${PROJECT_NAME})

include_directories(
    include
    )

file(GLOB physics_src src/*.cpp)
file(GLOB physics_hdr include/*.cpp)

add_library(${PROJECT_NAME} STATIC ${physics_src} ${physics_hdr})
