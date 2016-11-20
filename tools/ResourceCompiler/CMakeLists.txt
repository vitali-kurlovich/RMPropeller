cmake_minimum_required(VERSION 3.6)
project(ResourceCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/RMApplication.cpp)


include_directories(../../libs/sha1/include)

add_executable(ResourceCompiler ${SOURCE_FILES})
target_link_libraries(ResourceCompiler sha1)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shader DESTINATION ${CMAKE_CURRENT_BINARY_DIR})