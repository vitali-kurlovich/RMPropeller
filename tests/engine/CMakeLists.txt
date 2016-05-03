cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RMPropellerEngineTest

        common/RMTypeTest.cpp

        graphics/material/technique/pass/RMPassTest.cpp
        graphics/material/technique/pass/RMBlendTest.cpp
        graphics/material/technique/pass/RMDepthTest.cpp

        graphics/material/technique/shader/program/RMProgramTest.cpp

        graphics/material/technique/RMTechniqueTest.cpp

        graphics/geometry/mesh/attribute/RMVertexAttributeTest.cpp
        graphics/geometry/mesh/attribute/RMVertexAttributesTest.cpp
        graphics/geometry/mesh/buffer/RMVertexBufferTest.cpp
        graphics/geometry/mesh/buffer/3d/RMVertexBuffer3DTest.cpp
        graphics/texture/RMTextureTest.cpp)


target_link_libraries(RMPropellerEngineTest gtest gtest_main)