//
// Created by Vitali Kurlovich on 10/30/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/builder/RMVertexBufferHeaderBuilder.hpp>


using namespace rmengine;
using namespace graphics;


TEST(RMVertexBufferHeaderBuilder, V3fN3f) {
    RMVertexBufferHeaderBuilder builder;

    auto buildHeader = RMVertexBufferHeaderBuilder{}
            .append(RMVertexAttribute_Position, RMAttributeElementSize_3, RMType_Float)
            .append(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat)
            .append(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat).build();


    RMVertexBufferHeader header{
            RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_3, RMType_Float),
            RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_HalfFloat, 3*4),
            RMVertexAttributeItem(RMVertexAttribute_UV0, RMAttributeElementSize_2, RMType_HalfFloat, 3*4 + 3*2)
    };

    EXPECT_EQ(buildHeader, header);
}