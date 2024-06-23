cmake_minimum_required(VERSION 3.22.1)

set(project "poly")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        poly.cpp)

set(${project}_HEADERS
        poly.h)        

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})