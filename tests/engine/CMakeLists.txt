cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RMPropellerEngineTest
        graphics/material/RMPassTest.cpp
        graphics/material/RMBlendTest.cpp
        graphics/material/RMDepthTest.cpp
        )


target_link_libraries(RMPropellerEngineTest gtest gtest_main)