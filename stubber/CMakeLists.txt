cmake_minimum_required(VERSION 3.22)

project(Stubber VERSION 0.1.0)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_executable(main ./src/main.cpp)

target_sources(main
    PRIVATE
        src/main.cpp
        ${INCLUDE_DIR}/DSPExperiment.h
        ${INCLUDE_DIR}/DSPExperiment.cpp
)

# Sets the include directories of the plugin project.
target_include_directories(main
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(Stubber SHARED
    include/DSPExperiment.cpp
    include/DSPExperiment.h
)



