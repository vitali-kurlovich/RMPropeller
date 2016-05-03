//
// Created by Vitali Kurlovich on 5/2/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/buffer/RMVertexBuffer.hpp>


using namespace rmengine;
using  namespace graphics;

class MOCRMVertexBuffer : public RMVertexBuffer<uint32> {

public:
    MOCRMVertexBuffer(const RMVertexAttributes &attributes,  uint32 *buffer, const uint32 bufferSize)
            : RMVertexBuffer(attributes, buffer, bufferSize) { }

    MOCRMVertexBuffer(const RMVertexBuffer<uint32> &other) : RMVertexBuffer(other) { }
};

TEST(RMVertexBufferTest, constructor) {


    RMVertexAttributes attrs =
            {
                    RMVertexAttribute(RMVertexAttributeType_Position, RMAttributeElementSize_2),
                    RMVertexAttribute(RMVertexAttributeType_Normal, RMAttributeElementSize_3),
                    RMVertexAttribute(RMVertexAttributeType_UV2, RMAttributeElementSize_2)
            };


    uint32 buffer[] = {1,2,3,4,5};


    MOCRMVertexBuffer a(attrs, buffer, 5);

    EXPECT_EQ(a.getAttributes(), attrs);
    EXPECT_EQ(a.getVertexBuffer(), buffer);
    EXPECT_EQ(a.getBufferSize(), 5);

}