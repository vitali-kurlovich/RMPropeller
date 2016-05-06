//
// Created by Vitali Kurlovich on 5/1/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/VBO/buffer/attribute/RMVertexAttribute.hpp>


    using namespace rmengine;
    using  namespace graphics;

    TEST(RMVertexAttributeTest, constructor) {

    RMVertexAttribute a(RMVertexAttributeType_Position, RMAttributeElementSize_2);

    EXPECT_EQ(a.type, RMVertexAttributeType_Position);
    EXPECT_EQ(a.size, RMAttributeElementSize_2);
    EXPECT_EQ(a.offset, 0);


    RMVertexAttribute b(RMVertexAttributeType_Position, RMAttributeElementSize_2, RMType_Float, 12);

    EXPECT_EQ(b.type, RMVertexAttributeType_Position);
    EXPECT_EQ(b.size, RMAttributeElementSize_2);
    EXPECT_EQ(b.offset, 12);

    EXPECT_NE(a, b);

    a = b;

    EXPECT_EQ(a, b);

    RMVertexAttribute c(RMVertexAttributeType_Normal, RMAttributeElementSize_3, RMType_Float, 12);

    EXPECT_NE(a, c);
    a = c;

    EXPECT_EQ(a, c);

}
