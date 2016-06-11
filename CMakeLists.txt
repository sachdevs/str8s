cmake_minimum_required(VERSION 3.5)
project(str8s)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp)

add_executable(str8s ${SOURCE_FILES})