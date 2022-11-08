cmake_minimum_required(VERSION 3.19)
project(DataStructures)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(DataStructures
        LinkedList/LinkedList.cpp)
