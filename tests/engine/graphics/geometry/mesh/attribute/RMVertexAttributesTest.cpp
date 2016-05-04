//
// Created by Vitali Kurlovich on 5/1/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/buffer/attribute/RMVertexAttributes.hpp>

using namespace rmengine;
using namespace graphics;

TEST(RMVertexAttributesTest, constructor) {

    RMVertexAttributes a =
            {
                    RMVertexAttribute(RMVertexAttributeType_Position, RMAttributeElementSize_2),
                    RMVertexAttribute(RMVertexAttributeType_Normal, RMAttributeElementSize_3),
                    RMVertexAttribute(RMVertexAttributeType_UV2, RMAttributeElementSize_2)
            };

    EXPECT_EQ(a.attributes.size(), 3);
    EXPECT_EQ(a.type, (RMVertexAttributeType_Position | RMVertexAttributeType_Normal | RMVertexAttributeType_UV2));


    RMVertexAttributes b =
            {
                    RMVertexAttribute(RMVertexAttributeType_Position, RMAttributeElementSize_2),
                    RMVertexAttribute(RMVertexAttributeType_Normal, RMAttributeElementSize_3, RMType_Float, 2),
                    RMVertexAttribute(RMVertexAttributeType_UV2, RMAttributeElementSize_2, RMType_Float, 6)
            };

    EXPECT_NE(a, b);

    RMVertexAttributes c = {RMVertexAttribute(RMVertexAttributeType_Position, RMAttributeElementSize_2)};
    EXPECT_EQ(c.attributes.size(), 1);

    EXPECT_NE(a, c);

    a = c;

    EXPECT_EQ(a, c);
}
