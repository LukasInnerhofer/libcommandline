cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_STANDARD 20)

project(libcommandline)

add_library(${PROJECT_NAME}
    include/${PROJECT_NAME}/args.h
    include/${PROJECT_NAME}/flag.h
    include/${PROJECT_NAME}/option.h
    include/${PROJECT_NAME}/interface.h
    source/args.cpp
    source/flag.cpp
    source/interface.cpp
    source/option.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

get_target_property(LIBUTILITIES_INCLUDE_DIRECTORIES libutilities INCLUDE_DIRECTORIES)
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBUTILITIES_INCLUDE_DIRECTORIES})