cmake_minimum_required(VERSION 2.8)
project(TP7_8)

include_directories(src) # Pour que l'IDE inclu le contenu de mes headers
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -ansi -ggdb -std=c99")

# Macros du préprocesseur
#add_definitions(-DAVL)
add_definitions(-DARN)

#Repertoires executable et obj
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(OBJECT_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/obj")


set(SOURCE_FILES
        src/Avl.c
        src/Avl.h
        src/Collection.c
        src/Collection.h
        src/Element.c
        src/Element.h
        src/main.c src/Utils.h src/Utils.c src/Ascii.c src/Ascii.h src/Arn.c src/Arn.h)

add_executable(executable ${SOURCE_FILES})