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

    RMVertexBufferObjectBuilder builder(header, 32);

    EXPECT_EQ(builder.vertexCount(), 0);
    EXPECT_EQ(builder.indexesCount(), 0);

    builder.setVertex(0, RMVertexAttribute_Position, vec3(0.f,1.f,0.f))
    .setVertex(RMVertexAttribute_Normal, vec3(0.f,0.f,1.f));

    builder.setVertex(1, RMVertexAttribute_Position, vec3(0.f,2.f,0.f))
    .setVertex(RMVertexAttribute_Normal, vec3(0.f,0.f,2.f));

    builder.setVertex(2, RMVertexAttribute_Position, vec3(3.f,4.f,5.f))
    .setVertex(RMVertexAttribute_Normal, vec3(6.f,7.f,8.f));

    EXPECT_EQ(builder.vertexCount(), 3);
    EXPECT_EQ(builder.indexesCount(), 0);

    builder.setIndex(0, 2);

    EXPECT_EQ(builder.indexesCount(), 1);

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

    RMVertexBufferObjectBuilder builder(header, 32);

    EXPECT_EQ(builder.lastIndexPosition(), uint32_max);
    EXPECT_EQ(builder.lastVertexPosition(),uint32_max);

    builder.setVertex(0, RMVertexAttribute_Position, vec4(1.f,2.f,3.f,4.f))
    .setVertex(RMVertexAttribute_Color, vec4(10.f,20.f,30.f,40.f));

    EXPECT_EQ(builder.lastIndexPosition(), uint32_max);
    EXPECT_EQ(builder.lastVertexPosition(),0);

    builder.setVertex(2, RMVertexAttribute_Position, vec2(11.f,21.f))
    .setVertex(RMVertexAttribute_Normal, vec4(5.f,7.f));

    EXPECT_EQ(builder.lastIndexPosition(), uint32_max);
    EXPECT_EQ(builder.lastVertexPosition(),2);

    builder.setIndex(0, 2);

    EXPECT_EQ(builder.lastIndexPosition(), 0);
    EXPECT_EQ(builder.lastVertexPosition(),2);

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

    EXPECT_EQ(builder.lastIndexPosition(), 0);
    EXPECT_EQ(builder.lastVertexPosition(),1);


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

    EXPECT_EQ(builder.lastIndexPosition(), 0);
    EXPECT_EQ(builder.lastVertexPosition(),4);

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

    EXPECT_EQ(builder.vertexCount(), 5);
    EXPECT_EQ(builder.indexesCount(), 1);

    EXPECT_EQ(builder.lastIndexPosition(), 0);
    EXPECT_EQ(builder.lastVertexPosition(),3);

    builder.setIndex(1, 4);

    EXPECT_EQ(builder.vertexCount(), 5);
    EXPECT_EQ(builder.indexesCount(), 2);

    EXPECT_EQ(builder.lastIndexPosition(), 1);
    EXPECT_EQ(builder.lastVertexPosition(),3);

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


TEST(RMVertexBufferObjectBuilder, recalcBuffer) {

    RMVertexBufferHeader header;
    header.set(RMVertexAttribute_Position, RMAttributeElementSize_4, RMType_Float);
    header.set(RMVertexAttribute_Normal, RMAttributeElementSize_2, RMType_UInt16);
    header.set(RMVertexAttribute_UV3, RMAttributeElementSize_4, RMType_Int8);
    header.set(RMVertexAttribute_Color, RMAttributeElementSize_1, RMType_Int32);

    RMVertexBufferObjectBuilder builder(header, 4);

    builder.setVertex(0, RMVertexAttribute_Position, vec4(1.f,2.f,3.f,4.f))
            .setVertex(RMVertexAttribute_Color, vec4(10.f,20.f,30.f,40.f));

    builder.setVertex(2, RMVertexAttribute_Position, vec2(11.f,21.f))
            .setVertex(RMVertexAttribute_Normal, vec4(5.f,7.f));

    builder.setVertex(4, RMVertexAttribute_UV3, 12, 3, 100, int8_max)
            .setVertex(RMVertexAttribute_Color, 0x78903387)
            .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
            .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f));

    builder.setVertex(7, RMVertexAttribute_UV3, 12, 3, 100, int8_max)
            .setVertex(RMVertexAttribute_Color, 0x78903387)
            .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
            .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f));


    builder.setVertex(12, RMVertexAttribute_UV3, 12, 3, 100, int8_max)
            .setVertex(RMVertexAttribute_Color, 0x78903387)
            .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
            .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f));

    builder.setVertex(512, RMVertexAttribute_UV3, 12, 3, 100, int8_max)
            .setVertex(RMVertexAttribute_Color, 0x78903387)
            .setVertex(RMVertexAttribute_Normal, 0x1212, int16_max)
            .setVertex(RMVertexAttribute_Position, vec4(-55.f,66.f,-77.f,88.f));

    builder.setIndex(0, 512);

    EXPECT_EQ(builder.vertexCount(), 513);
    EXPECT_EQ(builder.indexesCount(), 1);

    using vertex = struct {
        vec4 pos;
        uint16 nx, ny;
        int32 color;
        int8 uvx, uvy, uvz, uvw;
    };

    auto vb = builder.build()->vertexBuffer();
    auto buffer = static_cast<vertex*>(vb->data());

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

    EXPECT_EQ(buffer[3].pos, vec4(0,0,0,0));
    EXPECT_EQ(buffer[3].nx, 0);
    EXPECT_EQ(buffer[3].ny, 0);
    EXPECT_EQ(buffer[3].color, 0);
    EXPECT_EQ(buffer[3].uvx, 0);
    EXPECT_EQ(buffer[3].uvy, 0);
    EXPECT_EQ(buffer[3].uvz, 0);
    EXPECT_EQ(buffer[3].uvw, 0);

    EXPECT_EQ(buffer[4].pos, vec4(-55.f,66.f,-77.f,88.f));
    EXPECT_EQ(buffer[4].nx, 0x1212);
    EXPECT_EQ(buffer[4].ny, int16_max);
    EXPECT_EQ(buffer[4].color, 0x78903387);
    EXPECT_EQ(buffer[4].uvx, 12);
    EXPECT_EQ(buffer[4].uvy, 3);
    EXPECT_EQ(buffer[4].uvz, 100);
    EXPECT_EQ(buffer[4].uvw, int8_max);


    for (uint32 index = 5; index < 7; ++index) {
        EXPECT_EQ(buffer[index].pos, vec4(0,0,0,0));
        EXPECT_EQ(buffer[index].nx, 0);
        EXPECT_EQ(buffer[index].ny, 0);
        EXPECT_EQ(buffer[index].color, 0);
        EXPECT_EQ(buffer[index].uvx, 0);
        EXPECT_EQ(buffer[index].uvy, 0);
        EXPECT_EQ(buffer[index].uvz, 0);
        EXPECT_EQ(buffer[index].uvw, 0);
    }

    EXPECT_EQ(buffer[7].pos, vec4(-55.f,66.f,-77.f,88.f));
    EXPECT_EQ(buffer[7].nx, 0x1212);
    EXPECT_EQ(buffer[7].ny, int16_max);
    EXPECT_EQ(buffer[7].color, 0x78903387);
    EXPECT_EQ(buffer[7].uvx, 12);
    EXPECT_EQ(buffer[7].uvy, 3);
    EXPECT_EQ(buffer[7].uvz, 100);
    EXPECT_EQ(buffer[7].uvw, int8_max);


    for (uint32 index = 8; index < 12; ++index) {
        EXPECT_EQ(buffer[index].pos, vec4(0,0,0,0));
        EXPECT_EQ(buffer[index].nx, 0);
        EXPECT_EQ(buffer[index].ny, 0);
        EXPECT_EQ(buffer[index].color, 0);
        EXPECT_EQ(buffer[index].uvx, 0);
        EXPECT_EQ(buffer[index].uvy, 0);
        EXPECT_EQ(buffer[index].uvz, 0);
        EXPECT_EQ(buffer[index].uvw, 0);
    }

    EXPECT_EQ(buffer[12].pos, vec4(-55.f,66.f,-77.f,88.f));
    EXPECT_EQ(buffer[12].nx, 0x1212);
    EXPECT_EQ(buffer[12].ny, int16_max);
    EXPECT_EQ(buffer[12].color, 0x78903387);
    EXPECT_EQ(buffer[12].uvx, 12);
    EXPECT_EQ(buffer[12].uvy, 3);
    EXPECT_EQ(buffer[12].uvz, 100);
    EXPECT_EQ(buffer[12].uvw, int8_max);


    for (uint32 index = 13; index < 512; ++index) {
        EXPECT_EQ(buffer[index].pos, vec4(0,0,0,0));
        EXPECT_EQ(buffer[index].nx, 0);
        EXPECT_EQ(buffer[index].ny, 0);
        EXPECT_EQ(buffer[index].color, 0);
        EXPECT_EQ(buffer[index].uvx, 0);
        EXPECT_EQ(buffer[index].uvy, 0);
        EXPECT_EQ(buffer[index].uvz, 0);
        EXPECT_EQ(buffer[index].uvw, 0);
    }


    EXPECT_EQ(buffer[512].pos, vec4(-55.f,66.f,-77.f,88.f));
    EXPECT_EQ(buffer[512].nx, 0x1212);
    EXPECT_EQ(buffer[512].ny, int16_max);
    EXPECT_EQ(buffer[512].color, 0x78903387);
    EXPECT_EQ(buffer[512].uvx, 12);
    EXPECT_EQ(buffer[512].uvy, 3);
    EXPECT_EQ(buffer[512].uvz, 100);
    EXPECT_EQ(buffer[512].uvw, int8_max);
}


TEST(RMVertexBufferObjectBuilder, build) {
    RMVertexBufferHeader header;
    header.set(RMVertexAttribute_Color, RMAttributeElementSize_1, RMType_Int8);
    RMVertexBufferObjectBuilder builder(header, 4);

    builder.setVertex(0, RMVertexAttribute_Color, 1)
            .setVertex(1, RMVertexAttribute_Color, 2)
            .setVertex(2, RMVertexAttribute_Color, 3)
            .setVertex(3, RMVertexAttribute_Color, 4)
            .setVertex(4, RMVertexAttribute_Color, 5)
            .setVertex(5, RMVertexAttribute_Color, 6);

    builder.appendIndex(0).appendIndex(2).appendIndex(3);

    auto vbo = builder.build();

    EXPECT_EQ(vbo->indexBuffer()->count(), 3);
    EXPECT_EQ(vbo->vertexBuffer()->size(), 4);

    builder.appendIndex(2).appendIndex(0).appendIndex(1);
    vbo = builder.build();

    EXPECT_EQ(vbo->indexBuffer()->count(), 6);
    EXPECT_EQ(vbo->vertexBuffer()->size(), 4);

    builder.appendIndex(5).appendIndex(4).appendIndex(3);

    vbo = builder.build();

    EXPECT_EQ(vbo->indexBuffer()->count(), 9);
    EXPECT_EQ(vbo->vertexBuffer()->size(), 6);


    EXPECT_EQ(vbo->indexBuffer()->type(), RMIntegerType_U8);
    EXPECT_EQ(vbo->indexBuffer()->size(), 9);

    builder.setVertex(256, RMVertexAttribute_Color, 256);
    builder.appendIndex(256);

    vbo = builder.build();

    EXPECT_EQ(vbo->indexBuffer()->count(), 10);
    EXPECT_EQ(vbo->vertexBuffer()->size(), 257);

    EXPECT_EQ(vbo->indexBuffer()->type(), RMIntegerType_U16);
    EXPECT_EQ(vbo->indexBuffer()->size(), 20);


    builder.setVertex(66000, RMVertexAttribute_Color, 256);
    builder.appendIndex(66000);

    vbo = builder.build();

    EXPECT_EQ(vbo->indexBuffer()->count(), 11);
    EXPECT_EQ(vbo->vertexBuffer()->size(), 66001);

    EXPECT_EQ(vbo->indexBuffer()->type(), RMIntegerType_U32);
    EXPECT_EQ(vbo->indexBuffer()->size(), 44);
}