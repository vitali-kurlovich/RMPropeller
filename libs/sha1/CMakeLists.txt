cmake_minimum_required(VERSION 3.0)

project(sha1)



set(HEADERS_LIB include/sha1.h)
set(SOURCE_LIB src/sha1.c)

add_library(sha1 STATIC ${SOURCE_LIB} ${HEADERS_LIB})
target_include_directories(sha1 PUBLIC include)
