cmake_minimum_required(VERSION 3.22)

set(project "lab7")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(Virtual_Classes)
add_subdirectory(MyVector)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} virtual_classes)
target_link_libraries(${project} myvector)