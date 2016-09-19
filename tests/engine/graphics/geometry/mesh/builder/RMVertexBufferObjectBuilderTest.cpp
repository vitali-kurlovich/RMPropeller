//
// Created by Vitali Kurlovich on 9/18/16.
//

#include "gtest/gtest.h"

#include <graphics/geometry/mesh/buffer/builder/RMVertexBufferObjectBuilder.hpp>


using namespace rmengine;
using namespace graphics;

TEST(RMVertexBufferObjectBuilder, V3fN3f) {

    RMVertexBufferHeader header;
    header.set(RMVertexAttribute_Position, RMAttributeElementSize_3, RMType_Float);
    header.set(RMVertexAttribute_Normal, RMAttributeElementSize_3, RMType_Float);

    RMVertexBufferObjectBuilder builder(header, 32, 32);

    builder.setVertex(0, RMVertexAttribute_Position, vec3(0.f,1.f,0.f))
    .setVertex(RMVertexAttribute_Normal, vec3(0.f,0.f,1.f));

    builder.setVertex(1, RMVertexAttribute_Position, vec3(0.f,2.f,0.f))
    .setVertex(RMVertexAttribute_Normal, vec3(0.f,0.f,2.f));

    builder.setVertex(2, RMVertexAttribute_Position, vec3(3.f,4.f,5.f))
    .setVertex(RMVertexAttribute_Normal, vec3(6.f,7.f,8.f));


    using v3_n3 = struct {
        vec3 pos;
        vec3 norm;
    };

    auto vbo = builder.build();
    v3_n3 *buffer = static_cast<v3_n3*>(vbo->vertexBuffer()->data());

    EXPECT_EQ(buffer[0].pos,  vec3(0.f,1.f,0.f));
    EXPECT_EQ(buffer[0].norm, vec3(0.f,0.f,1.f));

    EXPECT_EQ(buffer[1].pos,  vec3(0.f,2.f,0.f));
    EXPECT_EQ(buffer[1].norm, vec3(0.f,0.f,2.f));

    EXPECT_EQ(buffer[2].pos,  vec3(3.f,4.f,5.f));
    EXPECT_EQ(buffer[2].norm, vec3(6.f,7.f,8.f));

}

TEST(RMVertexBufferObjectBuilder, V3fN2usC1iUV4b) {
    RMVertexBufferHeader header;
    header.set(RMVertexAttribute_Position, RMAttributeElementSize_4, RMType_Float);
    header.set(RMVertexAttribute_Normal, RMAttributeElementSize_2, RMType_UInt16);
    header.set(RMVertexAttribute_UV3, RMAttributeElementSize_4, RMType_Int8);
    header.set(RMVertexAttribute_Color, RMAttributeElementSize_1, RMType_Int32);

    RMVertexBufferObjectBuilder builder(header, 32, 32);

    builder.setVertex(0, RMVertexAttribute_Position, vec4(1.f,2.f,3.f,4.f))
    .setVertex(RMVertexAttribute_Color, vec4(10.f,20.f,30.f,40.f));

    builder.setVertex(2, RMVertexAttribute_Position, vec2(11.f,21.f))
    .setVertex(RMVertexAttribute_Normal, vec4(5.f,7.f));

    using vertex = struct {
        vec4 pos;
        uint16 nx, ny;
        int32 color;
        int8 uvx, uvy, uvz, uvw;
    };

    auto vb = builder.build()->vertexBuffer();
    vertex *buffer = static_cast<vertex*>(vb->data());


    EXPECT_EQ(vb->attrCount(), 4);
    EXPECT_EQ(vb->attr(0), RMVertexAttributeItem(RMVertexAttribute_Position, RMAttributeElementSize_4, RMType_Float, 0));
    EXPECT_EQ(vb->attr(1), RMVertexAttributeItem(RMVertexAttribute_Normal, RMAttributeElementSize_2, RMType_UInt16, 16));
    EXPECT_EQ(vb->attr(2), RMVertexAttributeItem(RMVertexAttribute_Color, RMAttributeElementSize_1, RMType_Int32, 20));
    EXPECT_EQ(vb->attr(3), RMVertexAttributeItem(RMVertexAttribute_UV3, RMAttributeElementSize_4, RMType_Int8, 24));


    EXPECT_EQ(vb->size()/(4*4 + 2*2 + 4 + 4), 3);

    EXPECT_EQ(buffer[0].pos, vec4(1.f,2.f,3.f,4.f));
    EXPECT_EQ(buffer[0].nx, 0);
    EXPECT_EQ(buffer[0].ny, 0);
    EXPECT_EQ(buffer[0].color, 10);
    EXPECT_EQ(buffer[0].uvx, 0);
    EXPECT_EQ(buffer[0].uvy, 0);
    EXPECT_EQ(buffer[0].uvz, 0);
    EXPECT_EQ(buffer[0].uvw, 0);

    EXPECT_EQ(buffer[1].pos, vec4(0.f,0.f,0.f,0.f));
    EXPECT_EQ(buffer[1].nx, 0);
    EXPECT_EQ(buffer[1].ny, 0);
    EXPECT_EQ(buffer[1].color, 0);
    EXPECT_EQ(buffer[1].uvx, 0);
    EXPECT_EQ(buffer[1].uvy, 0);
    EXPECT_EQ(buffer[1].uvz, 0);
    EXPECT_EQ(buffer[1].uvw, 0);

    EXPECT_EQ(buffer[2].pos, vec4(11.f,21.f,0.f,0.f));
    EXPECT_EQ(buffer[2].nx, 5);
    EXPECT_EQ(buffer[2].ny, 7);
    EXPECT_EQ(buffer[2].color, 0);
    EXPECT_EQ(buffer[2].uvx, 0);
    EXPECT_EQ(buffer[2].uvy, 0);
    EXPECT_EQ(buffer[2].uvz, 0);
    EXPECT_EQ(buffer[2].uvw, 0);

    builder.setVertex(1, RMVertexAttribute_UV3, vec4(-55.f,66.f,-77.f,88.f));

    vb = builder.build()->vertexBuffer();
    buffer = static_cast<vertex*>(vb->data());

    EXPECT_EQ(vb->size()/(4*4 + 2*2 + 4 + 4), 3);

    EXPECT_EQ(buffer[0].pos, vec4(1.f,2.f,3.f,4.f));
    EXPECT_EQ(buffer[0].nx, 0);
    EXPECT_EQ(buffer[0].ny, 0);
    EXPECT_EQ(buffer[0].color, 10);
    EXPECT_EQ(buffer[0].uvx, 0);
    EXPECT_EQ(buffer[0].uvy, 0);
    EXPECT_EQ(buffer[0].uvz, 0);
    EXPECT_EQ(buffer[0].uvw, 0);

    EXPECT_EQ(buffer[1].pos, vec4(0.f,0.f,0.f,0.f));
    EXPECT_EQ(buffer[1].nx, 0);
    EXPECT_EQ(buffer[1].ny, 0);
    EXPECT_EQ(buffer[1].color, 0);
    EXPECT_EQ(buffer[1].uvx, -55);
    EXPECT_EQ(buffer[1].uvy, 66);
    EXPECT_EQ(buffer[1].uvz, -77);
    EXPECT_EQ(buffer[1].uvw, 88);

    EXPECT_EQ(buffer[2].pos, vec4(11.f,21.f,0.f,0.f));
    EXPECT_EQ(buffer[2].nx, 5);
    EXPECT_EQ(buffer[2].ny, 7);
    EXPECT_EQ(buffer[2].color, 0);
    EXPECT_EQ(buffer[2].uvx, 0);
    EXPECT_EQ(buffer[2].uvy, 0);
    EXPECT_EQ(buffer[2].uvz, 0);
    EXPECT_EQ(buffer[2].uvw, 0);

    builder.setVertex(4, RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f))
    .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
    .setVertex(RMVertexAttribute_Color, 0x78903387)
    .setVertex(RMVertexAttribute_UV3, 12, 3, 100, int8_max);

    builder.setVertex(4, RMVertexAttribute_UV3, 12, 3, 100, int8_max)
    .setVertex(RMVertexAttribute_Color, 0x78903387)
    .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
    .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f));


    builder.setVertex(3, RMVertexAttribute_UV3, 12, 3, 100, int8_max)
    .setVertex(RMVertexAttribute_Color, 0x78903387)
    .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
    .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f))
    .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f))
    .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
    .setVertex(RMVertexAttribute_Color, 0x78903387)
    .setVertex(RMVertexAttribute_UV3, 12, 3, 100, int8_max);

    vb = builder.build()->vertexBuffer();
    buffer = static_cast<vertex*>(vb->data());

    EXPECT_EQ(vb->size()/(4*4 + 2*2 + 4 + 4), 5);

    EXPECT_EQ(buffer[0].pos, vec4(1.f,2.f,3.f,4.f));
    EXPECT_EQ(buffer[0].nx, 0);
    EXPECT_EQ(buffer[0].ny, 0);
    EXPECT_EQ(buffer[0].color, 10);
    EXPECT_EQ(buffer[0].uvx, 0);
    EXPECT_EQ(buffer[0].uvy, 0);
    EXPECT_EQ(buffer[0].uvz, 0);
    EXPECT_EQ(buffer[0].uvw, 0);

    EXPECT_EQ(buffer[1].pos, vec4(0.f,0.f,0.f,0.f));
    EXPECT_EQ(buffer[1].nx, 0);
    EXPECT_EQ(buffer[1].ny, 0);
    EXPECT_EQ(buffer[1].color, 0);
    EXPECT_EQ(buffer[1].uvx, -55);
    EXPECT_EQ(buffer[1].uvy, 66);
    EXPECT_EQ(buffer[1].uvz, -77);
    EXPECT_EQ(buffer[1].uvw, 88);

    EXPECT_EQ(buffer[2].pos, vec4(11.f,21.f,0.f,0.f));
    EXPECT_EQ(buffer[2].nx, 5);
    EXPECT_EQ(buffer[2].ny, 7);
    EXPECT_EQ(buffer[2].color, 0);
    EXPECT_EQ(buffer[2].uvx, 0);
    EXPECT_EQ(buffer[2].uvy, 0);
    EXPECT_EQ(buffer[2].uvz, 0);
    EXPECT_EQ(buffer[2].uvw, 0);

    EXPECT_EQ(buffer[3].pos, vec4(-55.f,66.f,-77.f,88.f));
    EXPECT_EQ(buffer[3].nx, 0x1212);
    EXPECT_EQ(buffer[3].ny, int16_max);
    EXPECT_EQ(buffer[3].color, 0x78903387);
    EXPECT_EQ(buffer[3].uvx, 12);
    EXPECT_EQ(buffer[3].uvy, 3);
    EXPECT_EQ(buffer[3].uvz, 100);
    EXPECT_EQ(buffer[3].uvw, int8_max);

    EXPECT_EQ(buffer[4].pos, vec4(-55.f,66.f,-77.f,88.f));
    EXPECT_EQ(buffer[4].nx, 0x1212);
    EXPECT_EQ(buffer[4].ny, int16_max);
    EXPECT_EQ(buffer[4].color, 0x78903387);
    EXPECT_EQ(buffer[4].uvx, 12);
    EXPECT_EQ(buffer[4].uvy, 3);
    EXPECT_EQ(buffer[4].uvz, 100);
    EXPECT_EQ(buffer[4].uvw, int8_max);


}