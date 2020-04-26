cmake_minimum_required(VERSION 3.15)
project(Project_2_stuff)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_2_stuff main.cpp aStar.h interface.h controller.h grapher.h node.h grapher.cpp aStar.cpp controller.cpp interface.cpp)