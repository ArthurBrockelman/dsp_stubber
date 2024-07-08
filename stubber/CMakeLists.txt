cmake_minimum_required(VERSION 3.22)

# Version is needed by JUCE.
project(AudioPlugin VERSION 0.1.0)

# Adding a directory with the library/application name as a subfolder of the
# include folder is a good practice. It helps avoid name clashes later on.
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/YourPluginName")

# add include(CheckStructHasMember)
add_executable(main ./src/main.cpp)

get_filename_component(PARENT_DIR ../ ABSOLUTE)

message(${PARENT_DIR})

add_custom_command(
    OUTPUT ./stuff.txt 
    COMMAND ${PARENT_DIR}/libs/loris/configure 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
)

# Sets the include directories of the plugin project.
target_include_directories(main
    PUBLIC
        ${PARENT_DIR}/libs/loris/src/**
        ${CMAKE_CURRENT_SOURCE_DIR}/include/**
)

target_link_libraries(main
    PUBLIC
        ${PARENT_DIR}/libs/loris/src

)