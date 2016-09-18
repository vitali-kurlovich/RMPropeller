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

    header.set(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);

    EXPECT_EQ(header.count(), 1);
    EXPECT_EQ(header.format(), RMVertexAttribute_Position);
    EXPECT_EQ(header.size(), 12);

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_3, RMType_Float, 0));

    header.set(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    EXPECT_EQ(header.count(), 2);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal));
    EXPECT_EQ(header.size(), 18);

    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 12));


    header.set(RMVertexAttribute_Tangent, RMType_HalfFloat, RMAttributeElementSize_3);

    EXPECT_EQ(header.count(), 3);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent));
    EXPECT_EQ(header.size(), 24);

    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_HalfFloat, 18));


    header.set(RMVertexAttribute_UV0, RMType_HalfFloat, RMAttributeElementSize_2);

    EXPECT_EQ(header.count(), 4);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_UV0));
    EXPECT_EQ(header.size(), 28);

    EXPECT_EQ(header[3], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 24));

    header.set(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_2);

    EXPECT_EQ(header.count(), 4);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_UV0));
    EXPECT_EQ(header.size(), 24);

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_2, RMType_Float, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 8));
    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_HalfFloat, 14));
    EXPECT_EQ(header[3], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 20));


    header.set(RMVertexAttribute_Tangent, RMType_Float, RMAttributeElementSize_3);
    EXPECT_EQ(header.size(), 30);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_UV0));


    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_2, RMType_Float, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 8));
    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_Float, 14));
    EXPECT_EQ(header[3], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 26));

    header.set(RMVertexAttribute_Color, RMType_UInt8, RMAttributeElementSize_4);
    EXPECT_EQ(header.size(), 34);
    EXPECT_EQ(header.count(), 5);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_Color| RMVertexAttribute_UV0));

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_2, RMType_Float, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 8));
    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_Float, 14));
    EXPECT_EQ(header[3], RMVertexAttributeItem(RMVertexAttribute_Color, RMAttributeElementSize_4, RMType_UInt8, 26));
    EXPECT_EQ(header[4], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 30));


    header.remove(RMVertexAttribute_Position);
    EXPECT_EQ(header.size(), 26);
    EXPECT_EQ(header.count(), 4);
    EXPECT_EQ(header.format(), ( RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_Color| RMVertexAttribute_UV0));

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_Float, 6));
    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Color, RMAttributeElementSize_4, RMType_UInt8, 18));
    EXPECT_EQ(header[3], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 22));


    header.remove(RMVertexAttribute_Color);
    EXPECT_EQ(header.size(), 22);
    EXPECT_EQ(header.count(), 3);
    EXPECT_EQ(header.format(), ( RMVertexAttribute_Normal | RMVertexAttribute_Tangent | RMVertexAttribute_UV0));


    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_Float, 6));
    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 18));


    header.remove(RMVertexAttribute_UV0);
    EXPECT_EQ(header.size(), 18);
    EXPECT_EQ(header.count(), 2);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Normal | RMVertexAttribute_Tangent));

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_Float, 6));


    header.set(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    EXPECT_EQ(header.size(), 30);
    EXPECT_EQ(header.count(), 3);
    EXPECT_EQ(header.format(), (RMVertexAttribute_Position | RMVertexAttribute_Normal | RMVertexAttribute_Tangent));

    EXPECT_EQ(header[0], RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_3, RMType_Float, 0));
    EXPECT_EQ(header[1], RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 12));
    EXPECT_EQ(header[2], RMVertexAttributeItem(RMVertexAttribute_Tangent, RMAttributeElementSize_3, RMType_Float, 18));
}


TEST(RMVertexBufferHeader, nequal) {
    RMVertexBufferHeader a;

    a.set(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    a.set(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    RMVertexBufferHeader b;

    b.set(RMVertexAttribute_Position, RMType_HalfFloat, RMAttributeElementSize_3);
    b.set(RMVertexAttribute_Normal, RMType_Float, RMAttributeElementSize_3);

    EXPECT_NE(a,b);
}


TEST(RMVertexBufferHeader, equal) {
    RMVertexBufferHeader a;

    a.set(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    a.set(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    RMVertexBufferHeader b;

    b.set(RMVertexAttribute_Position, RMType_Float, RMAttributeElementSize_3);
    b.set(RMVertexAttribute_Normal, RMType_HalfFloat, RMAttributeElementSize_3);

    EXPECT_EQ(a,b);
}