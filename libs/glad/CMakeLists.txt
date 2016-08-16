cmake_minimum_required(VERSION 3.0)

project(glad)

include_directories(include)

set(SOURCE_LIB src/glad.c)

add_library(glad STATIC ${SOURCE_LIB})


