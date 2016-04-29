cmake_minimum_required(VERSION 3.5)
project(RMPropellerEngineTests)

add_subdirectory(libs/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
