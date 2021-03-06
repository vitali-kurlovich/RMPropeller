cmake_minimum_required(VERSION 3.5)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RMPropellerEngineTest

        common/RMTypeTest.cpp
        common/RMRangeTest.cpp
        common/RMColorTypeTest.cpp

        core/RMObjectTest.cpp
        core/system/memoryTest.cpp

        core/buffer/RMMemmoryPageTest.cpp
        core/buffer/RMMemmoryBufferTest.cpp

        core/serialize/RMCoderTest.cpp
        core/serialize/RMDecoderTest.cpp

        core/resorce/RMResourceHeaderTest.cpp

        graphics/material/technique/pass/RMPassTest.cpp
        graphics/material/technique/pass/RMBlendTest.cpp
        graphics/material/technique/pass/RMDepthTest.cpp

        graphics/material/technique/shader/program/RMProgramTest.cpp

        graphics/material/technique/RMTechniqueTest.cpp

        graphics/geometry/mesh/attribute/RMVertexAttributeTest.cpp
        graphics/geometry/mesh/RMVertexBufferHeaderTest.cpp

        graphics/geometry/mesh/builder/RMVertexBufferObjectBuilderTest.cpp
        graphics/geometry/mesh/builder/RMVertexBufferHeaderBuilderTest.cpp

        graphics/texture/RMTextureTest.cpp

        transform/TTransformTest.cpp
        transform/TTransform3dTest.cpp

        )


target_link_libraries(RMPropellerEngineTest gtest gtest_main)