cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_STANDARD 20)

project(libcommandline)

add_library(${PROJECT_NAME}
    include/${PROJECT_NAME}/args.h
    include/${PROJECT_NAME}/multi_option.h
    include/${PROJECT_NAME}/flag.h
    include/${PROJECT_NAME}/option.h
    include/${PROJECT_NAME}/option_with_argument.h
    include/${PROJECT_NAME}/single_option.h
    include/${PROJECT_NAME}/parser.h
    source/args.cpp
    source/multi_option.cpp
    source/flag.cpp
    source/option.cpp
    source/option_with_argument.cpp
    source/single_option.cpp
    source/parser.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

get_target_property(LIBUTILITIES_INCLUDE_DIRECTORIES libutilities INCLUDE_DIRECTORIES)
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBUTILITIES_INCLUDE_DIRECTORIES})