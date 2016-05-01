//
// Created by Vitali Kurlovich on 4/30/16.
//

#include "gtest/gtest.h"


#include <graphics/material/technique/RMTechnique.hpp>


using namespace rmengine::graphics;

TEST(RMDepthTest, constructor) {
    RMDepth a;

    EXPECT_TRUE(a.write);
    EXPECT_EQ(a.depthFunc, RMDepthFunc_Less);


    RMDepth b(false);
    EXPECT_FALSE(b.write);
    EXPECT_EQ(b.depthFunc, RMDepthFunc_Less);

    EXPECT_NE(a, b);


    RMDepth c(false, RMDepthFunc_Greater);

    EXPECT_NE(a, c);
    EXPECT_NE(b, c);

    EXPECT_FALSE(c.write);
    EXPECT_EQ(c.depthFunc, RMDepthFunc_Greater);

    a = c;

    EXPECT_EQ(a, c);
}