//
// Created by Vitali Kurlovich on 11/1/16.
//


#include "gtest/gtest.h"

#include <common/RMRange.hpp>

using namespace rmengine;

TEST(RMRangeTest, eq) {

    RMRange<int> rangeA{32, 200};
    RMRange<int> rangeB{32, 200};

    EXPECT_EQ(rangeA, rangeB);
    EXPECT_EQ(rangeA, rangeA);

    auto rangeA1 = RMRange<int>{0, 2};
    auto rangeB1 = RMRange<int>{0, 2};

    EXPECT_EQ(rangeA1, rangeB1);

    auto rangeA2 = RMRange<int>{6, 0};
    auto rangeB2 = RMRange<int>{6, 0};

    EXPECT_EQ(rangeA2, rangeB2);
}

TEST(RMRangeTest, neq) {

    auto rangeA = RMRange<int>{0, 2};
    auto rangeB = RMRange<int>{0, 3};

    EXPECT_NE(rangeA, rangeB);

    auto rangeA1 = RMRange<int>{6, 0};
    auto rangeB1 = RMRange<int>{7, 0};

    EXPECT_NE(rangeA1, rangeB1);

    auto rangeA2 = RMRange<int>{6, 10};
    auto rangeB2 = RMRange<int>{7, 11};

    EXPECT_NE(rangeA2, rangeB2);
}