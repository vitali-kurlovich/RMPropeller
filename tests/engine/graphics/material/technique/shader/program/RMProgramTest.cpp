//
// Created by Vitali Kurlovich on 5/1/16.
//




#include "gtest/gtest.h"
/*
#include "MOCRMProgram.hpp"

using namespace rmengine::graphics;

TEST(RMProgramTest, constructor) {

    MOCRMProgram a(true, true);

    EXPECT_FALSE(a.isCompiled());
    EXPECT_FALSE(a.hasError());

    EXPECT_TRUE(a.compile());

    EXPECT_TRUE(a.isCompiled());
    EXPECT_FALSE(a.hasError());
    EXPECT_TRUE(a.useProgram());

    MOCRMProgram b(false, true);

    EXPECT_FALSE(b.isCompiled());
    EXPECT_FALSE(b.hasError());

    EXPECT_FALSE(b.compile());

    EXPECT_TRUE(b.isCompiled());
    EXPECT_TRUE(b.hasError());
    EXPECT_FALSE(b.useProgram());
}


TEST(RMShaderProgramTest, constructor) {

    MOCRMVertexProgram vert(true, true);
    MOCRMPixelProgram pixel(true, true);

    RMShaderProgram shader(&vert, &pixel);

    EXPECT_EQ(shader.vertexProgram(), &vert);
    EXPECT_EQ(shader.pixelProgram(), &pixel);

    EXPECT_FALSE(shader.isCompiled());
    EXPECT_FALSE(shader.hasError());

    EXPECT_TRUE(shader.compile());
    EXPECT_TRUE(shader.isCompiled());
    EXPECT_FALSE(shader.hasError());

    EXPECT_TRUE(shader.useProgram());

}


TEST(RMShaderProgramTest, vertfail) {

    MOCRMVertexProgram vert(false, true);
    MOCRMPixelProgram pixel(true, true);

    RMShaderProgram shader(&vert, &pixel);

    EXPECT_EQ(shader.vertexProgram(), &vert);
    EXPECT_EQ(shader.pixelProgram(), &pixel);

    EXPECT_FALSE(shader.isCompiled());
    EXPECT_FALSE(shader.hasError());

    EXPECT_FALSE(shader.compile());

    EXPECT_TRUE(shader.isCompiled());
    EXPECT_TRUE(shader.hasError());

    EXPECT_FALSE(shader.useProgram());
}


TEST(RMShaderProgramTest, pixfail) {

    MOCRMVertexProgram vert(true, true);
    MOCRMPixelProgram pixel(false, true);

    RMShaderProgram shader(&vert, &pixel);

    EXPECT_EQ(shader.vertexProgram(), &vert);
    EXPECT_EQ(shader.pixelProgram(), &pixel);

    EXPECT_FALSE(shader.isCompiled());
    EXPECT_FALSE(shader.hasError());

    EXPECT_FALSE(shader.compile());

    EXPECT_TRUE(shader.isCompiled());
    EXPECT_TRUE(shader.hasError());

    EXPECT_FALSE(shader.useProgram());
}

 */