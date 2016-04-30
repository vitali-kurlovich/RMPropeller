//
// Created by Vitali Kurlovich on 4/30/16.
//


#include "gtest/gtest.h"


#include <graphics/material/pass/RMBlend.hpp>


using namespace rmengine::graphics;

TEST(RMBlendTest, constructor) {

    RMBlend a;

    EXPECT_EQ(a.src, RMBlendFunc_One);
    EXPECT_EQ(a.dst, RMBlendFunc_Zero);

    EXPECT_EQ(a.alphaSrc, RMBlendFunc_One);
    EXPECT_EQ(a.alphaDst, RMBlendFunc_Zero);

    EXPECT_EQ(a.equation, RMBlendEquation_Add);


    RMBlend b(RMBlendFunc_SrcColor,
              RMBlendFunc_OneMinusSrcColor,
              RMBlendFunc_ConstantColor,
              RMBlendFunc_OneMinusConstantAlpha,
              RMBlendEquation_ReverseSubtract);

    EXPECT_EQ(b.src, RMBlendFunc_SrcColor);
    EXPECT_EQ(b.dst, RMBlendFunc_OneMinusSrcColor);

    EXPECT_EQ(b.alphaSrc, RMBlendFunc_ConstantColor);
    EXPECT_EQ(b.alphaDst, RMBlendFunc_OneMinusConstantAlpha);

    EXPECT_EQ(b.equation, RMBlendEquation_ReverseSubtract);

    EXPECT_NE(a, b);

    a = b;

    EXPECT_EQ(a, b);
}
