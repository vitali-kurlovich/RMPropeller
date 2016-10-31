//
// Created by Vitali Kurlovich on 4/30/16.
//


#include "gtest/gtest.h"


#include <graphics/render/RMBlend.hpp>

using namespace rmengine::graphics;

TEST(RMBlendTest, constructor) {

    RMBlend a;

    EXPECT_EQ(a.src, RMBlend::RMBlendFunc_One);
    EXPECT_EQ(a.dst, RMBlend::RMBlendFunc_Zero);

    EXPECT_EQ(a.alphaSrc, RMBlend::RMBlendFunc_One);
    EXPECT_EQ(a.alphaDst, RMBlend::RMBlendFunc_Zero);

    EXPECT_FALSE(a.isRequireBlendEnable());

    RMBlend b(RMBlend::RMBlendFunc_SrcColor,
              RMBlend::RMBlendFunc_OneMinusSrcColor,
              RMBlend::RMBlendFunc_ConstantColor,
              RMBlend::RMBlendFunc_OneMinusConstantAlpha);

    EXPECT_EQ(b.src, RMBlend::RMBlendFunc_SrcColor);
    EXPECT_EQ(b.dst, RMBlend::RMBlendFunc_OneMinusSrcColor);

    EXPECT_EQ(b.alphaSrc, RMBlend::RMBlendFunc_ConstantColor);
    EXPECT_EQ(b.alphaDst, RMBlend::RMBlendFunc_OneMinusConstantAlpha);

    EXPECT_TRUE(b.isRequireBlendEnable());


    EXPECT_NE(a, b);

    a = b;

    EXPECT_EQ(a, b);


    RMBlend c(RMBlend::RMBlendFunc_SrcColor, RMBlend::RMBlendFunc_DstColor);

    EXPECT_EQ(c.src, RMBlend::RMBlendFunc_SrcColor);
    EXPECT_EQ(c.dst, RMBlend::RMBlendFunc_DstColor);

    EXPECT_EQ(c.alphaSrc, RMBlend::RMBlendFunc_SrcColor);
    EXPECT_EQ(c.alphaDst, RMBlend::RMBlendFunc_DstColor);

    EXPECT_TRUE(c.isRequireBlendEnable());

}
