
cmake_minimum_required(VERSION 3.5)
project(RMPropellerEngine)

add_definitions(-std=c++11)

include_directories(../libs)

set(HEADER_FILES)
set(SOURCE_FILES)



#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)