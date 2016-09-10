//
// Created by Vitali Kurlovich on 8/20/16.
//

#include "gtest/gtest.h"

#include <common/RMColorType.hpp>

using namespace rmengine;

TEST(RMColorTypeTest, constructor) {


    RMColorRGB color;

    EXPECT_EQ(color.r, 0);
    EXPECT_EQ(color.g, 0);
    EXPECT_EQ(color.b, 0);

    RMColorRGB color_1(3,5,7);

    EXPECT_EQ(color_1.r, 3);
    EXPECT_EQ(color_1.g, 5);
    EXPECT_EQ(color_1.b, 7);


    RMColorRGBA color_2(13,15,17, 50);

    EXPECT_EQ(color_2.r, 13);
    EXPECT_EQ(color_2.g, 15);
    EXPECT_EQ(color_2.b, 17);
    EXPECT_EQ(color_2.a, 50);

    color_2 = color_1;

    EXPECT_EQ(color_2.r, 3);
    EXPECT_EQ(color_2.g, 5);
    EXPECT_EQ(color_2.b, 7);
    EXPECT_EQ(color_2.a, 255);

    RMColorRGB c(63, 127, 255);
    RMColorRGB_F cf = c;

    EXPECT_FLOAT_EQ(cf.r, 63/255.f);
    EXPECT_FLOAT_EQ(cf.g, 127/255.f);
    EXPECT_FLOAT_EQ(cf.b, 1.f);

    cf = RMColorRGB_F(1.f, 0.5f, 0.25f);
    c = cf;

    EXPECT_EQ(c.r, 255);
    EXPECT_EQ(c.g, 127);
    EXPECT_EQ(c.b, 63);


    RMColorRGBA ca(63, 127, 255, 31);
    RMColorRGBA_F caf(ca);

    EXPECT_FLOAT_EQ(caf.r, 63/255.f);
    EXPECT_FLOAT_EQ(caf.g, 127/255.f);
    EXPECT_FLOAT_EQ(caf.b, 1.f);
    EXPECT_FLOAT_EQ(caf.a, 31/255.f);

    caf = RMColorRGBA_F(0.125f, 0.5f, 0.25f, 1.f);
    ca = caf;

    EXPECT_EQ(ca.r, 31);
    EXPECT_EQ(ca.g, 127);
    EXPECT_EQ(ca.b, 63);
    EXPECT_EQ(ca.a, 255);

}