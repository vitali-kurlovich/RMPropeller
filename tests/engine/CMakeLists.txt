cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RMPropellerEngineTest
        graphics/material/technique/RMPassTest.cpp
        graphics/material/technique/RMBlendTest.cpp
        graphics/material/technique/RMDepthTest.cpp
        )


target_link_libraries(RMPropellerEngineTest gtest gtest_main)