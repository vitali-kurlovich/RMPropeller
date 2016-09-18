//
// Created by Vitali Kurlovich on 5/1/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/buffer/RMVertexAttribute.hpp>


    using namespace rmengine;
    using namespace graphics;

    TEST(RMVertexAttributeTest, constructor) {

    RMVertexAttributeItem a(RMVertexAttribute_Position, RMAttributeElementSize_2);

    EXPECT_EQ(a.attribute, RMVertexAttribute_Position);
    EXPECT_EQ(a.size, RMAttributeElementSize_2);
    EXPECT_EQ(a.type, RMType_Float);
    EXPECT_EQ(a.offset, 0);


    RMVertexAttributeItem b(RMVertexAttribute_Position, RMAttributeElementSize_2, RMType_Float, 12);

    EXPECT_EQ(b.attribute, RMVertexAttribute_Position);
    EXPECT_EQ(b.type, RMType_Float);
    EXPECT_EQ(b.size, RMAttributeElementSize_2);
    EXPECT_EQ(b.offset, 12);

    EXPECT_NE(a, b);

    a = b;

    EXPECT_EQ(a, b);

    RMVertexAttributeItem c(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_Float, 12);

    EXPECT_NE(a, c);
    a = c;

    EXPECT_EQ(a, c);

}
