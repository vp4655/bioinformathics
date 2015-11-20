cmake_minimum_required(VERSION 3.3)
project(bioinformatics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RedBlackTree.cpp RedBlackTree.h)
add_executable(bioinformatics ${SOURCE_FILES})