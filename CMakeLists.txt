cmake_minimum_required(VERSION 3.5)
project(RMPropeller)

include_directories(engine)

add_subdirectory(engine)
add_subdirectory(tests)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

        main.cpp

        )

add_executable(RMPropeller ${SOURCE_FILES})
target_link_libraries(RMPropeller ${OPENGL_LIBRARIES} )
