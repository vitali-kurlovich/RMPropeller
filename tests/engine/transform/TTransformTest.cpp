//
// Created by Vitali Kurlovich on 8/4/16.
//

#include "gtest/gtest.h"

#include <transform/TTransform.hpp>

using namespace rmengine;

TEST(Transform, constructor) {

    TTransform tm;

    EXPECT_EQ(tm.getParent(), nullptr);
    EXPECT_FALSE(tm.hasParent());

}
