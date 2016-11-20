cmake_minimum_required(VERSION 3.5)
project(RMPropellerEngineTests)

add_definitions(-std=c++11)


add_subdirectory(libs/googletest)


include_directories(../libs/sha1/include)
add_subdirectory(engine)
