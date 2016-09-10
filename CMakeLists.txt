cmake_minimum_required(VERSION 3.5)
project(RMPropeller)

include_directories(engine)

add_subdirectory(engine)
add_subdirectory(tests)



#########################################################
# GLFW
#########################################################

add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

add_subdirectory(libs/glad)
include_directories(libs/glad/include)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

        main.cpp

        )

add_executable(RMPropeller ${SOURCE_FILES})
target_link_libraries(RMPropeller glad)
target_link_libraries(RMPropeller glfw ${GLFW_LIBRARIES})


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shader DESTINATION ${CMAKE_CURRENT_BINARY_DIR})