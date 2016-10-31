//
// Created by Vitali Kurlovich on 4/29/16.
//

#include "gtest/gtest.h"

#include <graphics/render/technique/RMTechnique.hpp>


using namespace rmengine::graphics;

TEST(RMPassTest, constructor) {

   // RMShaderProgram shader(nullptr);
    RMPass a;


    RMDepth depth;
    RMBlend blend;

    EXPECT_EQ(a.getDepth(), depth);
    EXPECT_EQ(a.getBlend(), blend);
    EXPECT_EQ(a.getCullFace(), RMPass::RMCullFace_Back);

    EXPECT_FALSE(a.requireBlendEnable());
    EXPECT_FALSE(a.requireDepthSort());
    EXPECT_TRUE(a.isRequireCullFaceEnable());


    RMPass b(RMPass::RMCullFace_None, RMPass::RMDepthSort_Reverse);

    EXPECT_EQ(b.getDepth(), depth);
    EXPECT_EQ(b.getBlend(), blend);
    EXPECT_EQ(b.getCullFace(), RMPass::RMCullFace_None);

    EXPECT_FALSE(b.requireBlendEnable());
    EXPECT_TRUE(b.requireDepthSort());

    EXPECT_FALSE(b.isRequireCullFaceEnable());


    RMDepth depth_b(false, RMDepth::RMDepthFunc_Greater);
    RMBlend blend_b(RMBlend::RMBlendFunc_SrcColor, RMBlend::RMBlendFunc_DstColor);

    RMPass c(depth_b, blend_b, RMPass::RMCullFace_None, RMPass::RMDepthSort_Forward);



    EXPECT_EQ(c.getDepth(), depth_b);
    EXPECT_EQ(c.getBlend(), blend_b);
    EXPECT_EQ(c.getCullFace(), RMPass::RMCullFace_None);

    EXPECT_TRUE(c.requireBlendEnable());
    EXPECT_TRUE(c.requireDepthSort());

    EXPECT_FALSE(c.isRequireCullFaceEnable());


}
