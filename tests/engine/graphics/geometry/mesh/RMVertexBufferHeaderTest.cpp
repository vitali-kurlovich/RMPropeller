//
// Created by Vitali Kurlovich on 9/12/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/buffer/RMVertexBufferHeader.hpp>


using namespace rmengine;
using namespace graphics;

TEST(RMVertexBufferHeader, constructor) {

    RMVertexBufferHeader header;

    EXPECT_EQ(header.count(), 0);
    EXPECT_EQ(header.format(), 0);
    EXPECT_EQ(header.size(), 0);


    header.append(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);

    EXPECT_EQ(header.count(), 1);
    EXPECT_EQ(header.format(), RMVertexAttribute_Position);
    EXPECT_EQ(header.size(), 12);

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_3, RMType_Float, 0));

    header.append(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    EXPECT_EQ(header.count(), 2);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal));
    EXPECT_EQ(header.size(), 18);

    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 12));

    header.append(RMVertexAttribute_Tangent, RMType_HalfFloat, RMAttributeElementSize_3);

    EXPECT_EQ(header.count(), 3);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent));
    EXPECT_EQ(header.size(), 24);

    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_HalfFloat, 18));


    header.append(RMVertexAttribute_UV0, RMType_HalfFloat, RMAttributeElementSize_2);

    EXPECT_EQ(header.count(), 4);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_UV0));
    EXPECT_EQ(header.size(), 28);

    EXPECT_EQ(header[3], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 24));


}


TEST(RMVertexBufferHeader, nequal) {
    RMVertexBufferHeader a;

    a.append(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    a.append(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    RMVertexBufferHeader b;

    b.append(RMVertexAttribute_Position, RMType_HalfFloat, RMAttributeElementSize_3);
    b.append(RMVertexAttribute_Normal, RMType_Float, RMAttributeElementSize_3);

    EXPECT_NE(a,b);
}


TEST(RMVertexBufferHeader, equal) {
    RMVertexBufferHeader a;

    a.append(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    a.append(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    RMVertexBufferHeader b;

    b.append(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    b.append(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    EXPECT_EQ(a,b);
}