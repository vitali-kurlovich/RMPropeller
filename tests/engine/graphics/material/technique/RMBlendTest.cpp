//
// Created by Vitali Kurlovich on 4/30/16.
//


#include "gtest/gtest.h"


#include <graphics/material/technique/RMTechnique.hpp>

using namespace rmengine::graphics;

TEST(RMBlendTest, constructor) {

    RMBlend a;

    EXPECT_EQ(a.src, RMBlendFunc_One);
    EXPECT_EQ(a.dst, RMBlendFunc_Zero);

    EXPECT_EQ(a.alphaSrc, RMBlendFunc_One);
    EXPECT_EQ(a.alphaDst, RMBlendFunc_Zero);

    EXPECT_FALSE(a.requireBlendEnable());

    RMBlend b(RMBlendFunc_SrcColor,
              RMBlendFunc_OneMinusSrcColor,
              RMBlendFunc_ConstantColor,
              RMBlendFunc_OneMinusConstantAlpha);

    EXPECT_EQ(b.src, RMBlendFunc_SrcColor);
    EXPECT_EQ(b.dst, RMBlendFunc_OneMinusSrcColor);

    EXPECT_EQ(b.alphaSrc, RMBlendFunc_ConstantColor);
    EXPECT_EQ(b.alphaDst, RMBlendFunc_OneMinusConstantAlpha);

    EXPECT_TRUE(b.requireBlendEnable());


    EXPECT_NE(a, b);

    a = b;

    EXPECT_EQ(a, b);


    RMBlend c(RMBlendFunc_SrcColor, RMBlendFunc_DstColor);

    EXPECT_EQ(c.src, RMBlendFunc_SrcColor);
    EXPECT_EQ(c.dst, RMBlendFunc_DstColor);

    EXPECT_EQ(c.alphaSrc, RMBlendFunc_SrcColor);
    EXPECT_EQ(c.alphaDst, RMBlendFunc_DstColor);

    EXPECT_TRUE(c.requireBlendEnable());

}
