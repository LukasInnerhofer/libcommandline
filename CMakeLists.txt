cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_STANDARD 20)

project(libcommandline)

add_library(${PROJECT_NAME}
    include/${PROJECT_NAME}/option.h
    source/option.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)