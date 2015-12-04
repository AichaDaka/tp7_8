cmake_minimum_required(VERSION 2.8)
project(TP7_8)
include_directories(src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/AVL.c
        src/AVL.h
        src/Collection.c
        src/Collection.h
        src/Element.c
        src/Element.h
        src/main.c)

add_executable(executable ${SOURCE_FILES})