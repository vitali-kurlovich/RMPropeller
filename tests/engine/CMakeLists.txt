cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RMPropellerEngineTest

        common/RMTypeTest.cpp
        common/RMColorTypeTest.cpp

        core/RMObjectTest.cpp

        graphics/material/technique/pass/RMPassTest.cpp
        graphics/material/technique/pass/RMBlendTest.cpp
        graphics/material/technique/pass/RMDepthTest.cpp

        graphics/material/technique/shader/program/RMProgramTest.cpp

        graphics/material/technique/RMTechniqueTest.cpp

        graphics/geometry/mesh/attribute/RMVertexAttributeTest.cpp
        graphics/geometry/mesh/RMVertexBufferHeaderTest.cpp

        graphics/texture/RMTextureTest.cpp

        transform/TTransformTest.cpp
        transform/TTransform3dTest.cpp

        )


target_link_libraries(RMPropellerEngineTest gtest gtest_main)