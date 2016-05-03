//
// Created by Vitali Kurlovich on 5/2/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/buffer/3d/RMVertexBuffer3D.hpp>


using namespace rmengine;
using namespace graphics;

TEST(RMVertexBuffer3DTest, constructor_P3_N3_C4_U0_U1) {


    RMVertexBufferBase a = RMVertexBuffer_P3_N3_C4_U0_U1(nullptr, 0);

    RMVertexAttributes attrs = {
            RMVertexAttribute(RMVertexAttributeType_Position, RMAttributeElementSize_3),
            RMVertexAttribute(RMVertexAttributeType_Normal, RMAttributeElementSize_3),
            RMVertexAttribute(RMVertexAttributeType_Color, RMAttributeElementSize_4),
            RMVertexAttribute(RMVertexAttributeType_UV0, RMAttributeElementSize_2),
            RMVertexAttribute(RMVertexAttributeType_UV1, RMAttributeElementSize_2),
    };

    EXPECT_EQ(a.getAttributes(), attrs);

}