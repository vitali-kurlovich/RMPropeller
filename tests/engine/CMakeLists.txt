cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RMPropellerEngineTest
        graphics/material/technique/pass/RMPassTest.cpp
        graphics/material/technique/pass/RMBlendTest.cpp
        graphics/material/technique/pass/RMDepthTest.cpp

        graphics/material/technique/shader/program/RMProgramTest.cpp

        graphics/material/technique/RMTechniqueTest.cpp

        graphics/geometry/mesh/attribute/RMVertexAttributeTest.cpp
        graphics/geometry/mesh/attribute/RMVertexAttributesTest.cpp)


target_link_libraries(RMPropellerEngineTest gtest gtest_main)