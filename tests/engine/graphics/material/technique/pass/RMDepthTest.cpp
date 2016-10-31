//
// Created by Vitali Kurlovich on 4/30/16.
//

#include "gtest/gtest.h"


#include <graphics/render/RMDepth.hpp>


using namespace rmengine::graphics;

TEST(RMDepthTest, constructor) {
    RMDepth a;

    EXPECT_TRUE(a.isRequireWrite());
    EXPECT_EQ(a.getDepthFunc(), RMDepth::RMDepthFunc_Less);


    RMDepth b(false);
    EXPECT_FALSE(b.isRequireWrite());
    EXPECT_EQ(b.getDepthFunc(), RMDepth::RMDepthFunc_Less);

    EXPECT_NE(a, b);


    RMDepth c(false, RMDepth::RMDepthFunc_Greater);

    EXPECT_NE(a, c);
    EXPECT_NE(b, c);

    EXPECT_FALSE(c.isRequireWrite());
    EXPECT_EQ(c.getDepthFunc(), RMDepth::RMDepthFunc_Greater);

    a = c;

    EXPECT_EQ(a, c);
}