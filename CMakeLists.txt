cmake_minimum_required(VERSION 3.3)
project(bioinformatics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp RedBlackTree.cpp RedBlackTree.h Node.cpp Node.h color.h wTree.cpp Data.h Data.cpp wNode.h wTree.h CreateTree.h CreateTree.cpp )
add_executable(bioinformatics ${SOURCE_FILES})