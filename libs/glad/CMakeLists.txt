cmake_minimum_required(VERSION 3.0)

project(glad)

set(SOURCE_LIB src/glad.c)
set(HEADERS_LIB include/glad/glad.h)

add_library(glad STATIC ${SOURCE_LIB} ${HEADERS_LIB})
target_include_directories(glad PUBLIC include)
