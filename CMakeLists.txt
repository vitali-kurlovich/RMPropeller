cmake_minimum_required(VERSION 3.5)
project(RMPropeller)

include_directories(engine)

add_subdirectory(engine)
add_subdirectory(tests)


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


#########################################################
# GLFW
#########################################################

add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

        main.cpp

        )

add_executable(RMPropeller ${SOURCE_FILES})
target_link_libraries(RMPropeller ${OPENGL_LIBRARIES} )
target_link_libraries(RMPropeller glfw ${GLFW_LIBRARIES})
