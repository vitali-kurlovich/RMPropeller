//
// Created by Vitali Kurlovich on 4/29/16.
//

#include "gtest/gtest.h"

#include <graphics/material/technique/RMTechnique.hpp>


using namespace rmengine::graphics;

TEST(RMPassTest, constructor) {

    RMShader shader(nullptr);
    RMPass a(&shader);

    EXPECT_EQ(a.getShader(), &shader);

    RMDepth depth;
    RMBlend blend;

    EXPECT_EQ(a.getDepth(), depth);
    EXPECT_EQ(a.getBlend(), blend);
    EXPECT_EQ(a.getCullFace(), RMCullFace_Back);

    EXPECT_FALSE(a.requireBlendEnable());
    EXPECT_FALSE(a.requireDepthSort());
    EXPECT_TRUE(a.requireCullFaceEnable());


    RMPass b(nullptr, RMCullFace_None, true);
    EXPECT_EQ(b.getShader(), nullptr);

    EXPECT_EQ(b.getDepth(), depth);
    EXPECT_EQ(b.getBlend(), blend);
    EXPECT_EQ(b.getCullFace(), RMCullFace_None);

    EXPECT_FALSE(b.requireBlendEnable());
    EXPECT_TRUE(b.requireDepthSort());

    EXPECT_FALSE(b.requireCullFaceEnable());


    RMDepth depth_b(false, RMDepthFunc_Greater);
    RMBlend blend_b(RMBlendFunc_SrcColor, RMBlendFunc_DstColor);

    RMPass c(depth_b, blend_b, &shader, RMCullFace_None, true);

    EXPECT_EQ(c.getShader(), &shader);

    EXPECT_EQ(c.getDepth(), depth_b);
    EXPECT_EQ(c.getBlend(), blend_b);
    EXPECT_EQ(c.getCullFace(), RMCullFace_None);

    EXPECT_TRUE(c.requireBlendEnable());
    EXPECT_TRUE(c.requireDepthSort());

    EXPECT_FALSE(c.requireCullFaceEnable());


}
