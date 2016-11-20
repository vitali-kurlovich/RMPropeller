
cmake_minimum_required(VERSION 3.5)
project(RMPropellerEngine)

include_directories(../libs/glad/include)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(../libs)
include_directories(../libs/math/rmvmath)


set(HEADER_FILES)
set(SOURCE_FILES core/resorce/sha1/RMSHA1.cpp)
